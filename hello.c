/*
 * Hello world example
 */
#include <rtems.h>
#include <stdlib.h>
#include <stdio.h>

#include <rtems/shell.h>
#include <rtems/untar.h>

void SetupFileSystem();
int LSeekStressTest();
int   RamTest();
int fail_count = 0;

int lock_interrupts = 0;

rtems_task Init(
  rtems_task_argument ignored
)
{
    int fails_int = 0;
    int fails_no_int = 0;
    rtems_status_code sc = RTEMS_SUCCESSFUL;
  printf( "\nStarting tests World\n" );
  RamTest();


  SetupFileSystem();
  int i = 0;
  while(1){
    lock_interrupts = 0;
    fail_count = 0;
    LSeekStressTest();
    fails_int += fail_count;

    lock_interrupts = 1;
    fail_count = 0;
    LSeekStressTest();
    fails_no_int += fail_count;

    printf("%03d Int Fail Count %3d No Int Fail %3d\n",i, fails_int, fails_no_int);
    i += 1;
  }

  for(int i=0;i<10;i++){
    printf("%02d ",i);
    LSeekStressTest();
  }


  printf( "\nTestDone\n" );
  exit( 0 );
}
rtems_interrupt_lock_context lock_contex;
rtems_interrupt_lock interrupt_lock;
extern const unsigned char config_tar[];
extern const size_t config_tar_size;

void SetupFileSystem(){
    if (config_tar_size > 0)
    {
        printf("Unpacking tar filesystem, this may take awhile...\n");
        const unsigned char* ptr = config_tar;

        if (Untar_FromMemory((char*) config_tar, config_tar_size) != 0)
        {
            printf("Can't unpack tar filesystem\n");
            exit(1);
        }
    }
}




#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define FILENAME "core-cpu1.exe"
#define TEST_OFFSET 0x1b3d70   // Some arbitrary offset

#define BUFFER_SIZE 2048
#define STRESS_COUNT 100000   // Read 100k times


// extern void microblaze_disable_icache();
// extern void microblaze_disable_dcache();

int RamTest(){
    // microblaze_disable_icache();
    // microblaze_disable_dcache();
    uint32_t buffer[BUFFER_SIZE/4];
    int num_ints = BUFFER_SIZE/4;
    uint32_t value;
    volatile  uint32_t * memory = (uint32_t*) config_tar;
    int mem_size = config_tar_size;
    int ram_offset = 0;

    #define CACHE_SIZE (0x8000)
    if(CACHE_SIZE > config_tar_size){
        printf("TODO FIX CACHE SIZE %d \n",config_tar_size);
        return -1;
    }
    uint32_t EXPECTED_VALUE = memory[0];
    for (int i = 0; i < STRESS_COUNT; i++) {

        memcpy(buffer, &config_tar[ram_offset], BUFFER_SIZE);
        memcpy(&value, buffer, sizeof(value));

        if (value != EXPECTED_VALUE) {
            printf("Mismatched value at iteration %d. Expected: 0x%x, Got: 0x%x memory address is 0X%08x\n",
                i, EXPECTED_VALUE, memory[0], memory);
            break;
        }

        memcpy(buffer, &config_tar[0x8000], 100);
        memset(buffer, 0x39, sizeof(buffer));
    }
    printf("RAM TEST PASSED\n");
    return 0;
}


void do_some_work(int fd) {
    char buffer[100];
    lseek(fd, 0x2000, SEEK_SET); // Seek to a different offset
    read(fd, buffer, sizeof(buffer)); // Read some data from the new offset
}
int LSeekStressTest() {
    int fd;
    uint32_t value;
    char buffer[BUFFER_SIZE];
    int count = 0;
    uint32_t EXPECTED_VALUE = 0x07e8;

    fd = open(FILENAME, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        exit(1);
    }

    for (int i = 0; i < STRESS_COUNT; i++) {
        if(lock_interrupts){
            rtems_interrupt_lock_acquire(interrupt_lock, &lock_contex);
        }
        int status = lseek(fd, TEST_OFFSET, SEEK_SET);
        if (read(fd, buffer, BUFFER_SIZE) != BUFFER_SIZE) {
            perror("Failed to read from file");
            printf("status is %d, ftell is %d\n", status, lseek(fd, 0, SEEK_CUR));
            close(fd);
            exit(1);

        }



        memcpy(&value, buffer, sizeof(value));
        if(lock_interrupts){
            rtems_interrupt_lock_release(interrupt_lock, &lock_contex);
        }    
        if(i == 0){
          EXPECTED_VALUE = value;
        }

        if (value != EXPECTED_VALUE) {
            printf("Mismatched value at iteration %d. Expected: 0x%x, Got: 0x%x : fpos %d\n",
                   i, EXPECTED_VALUE, value,  lseek(fd, 0, SEEK_CUR));

            // i = STRESS_COUNT - 2;
            // break;
            fail_count++;
        }

        count++;
        memset(buffer, 0x39, sizeof(buffer));
        // Do some other activity every 100 reads
        // if (i % 2 == 0) {
            do_some_work(fd);
        // }
    }
    if(fail_count== 0)
        printf("Completed %d reads successfully\n", count);
    else{
        printf("Completed %d reads total fails at %d\n", count,fail_count);

    }
    close(fd);
    return 0;
}