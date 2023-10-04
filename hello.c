/*
 * Hello world example
 */
#include <rtems.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include <rtems/shell.h>
#include <rtems/untar.h>


#define FILENAME "core-cpu1.exe"
#define TEST_OFFSET 0x1b3d70   // Some arbitrary offset

#define BUFFER_SIZE 2048
#define STRESS_COUNT 100000   // Read 100k times


void SetupFileSystem();
int LSeekStressTest(int lock_interrupts);

int lock_interrupts = 0;

rtems_task Init(
  rtems_task_argument ignored
)
{
    int fails_int = 0;
    int fails_no_int = 0;
    rtems_status_code sc = RTEMS_SUCCESSFUL;
    printf( "\nStarting interrupt fseek tests \n" );


    SetupFileSystem();
    int i = 0;
    while(1){


        fails_int += LSeekStressTest(lock_interrupts = 0);
        printf("%03d Int Fail Count %3d No Int Fail %3d\n",i, fails_int, fails_no_int);

        fails_no_int += LSeekStressTest(lock_interrupts = 1);
        printf("%03d Int Fail Count %3d No Int Fail %3d\n",i, fails_int, fails_no_int);
        i += 1;
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

void do_some_work(int fd) {
    char buffer[100];
    lseek(fd, 0x2000, SEEK_SET); // Seek to a different offset
    read(fd, buffer, sizeof(buffer)); // Read some data from the new offset
}
int LSeekStressTest(int lock_interrupts) {
    int fd;
    uint32_t value;
    char buffer[BUFFER_SIZE];
    int count = 0;
    uint32_t EXPECTED_VALUE = 0x07e8;
    int fail_count = 0;

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
        /* Set expected value based off first load.*/
        if(i == 0){
          EXPECTED_VALUE = value;
        }

        if (value != EXPECTED_VALUE) {
            printf("Mismatched value at iteration %d. Expected: 0x%x, Got: 0x%x : fpos %d\n",
                   i, EXPECTED_VALUE, value,  lseek(fd, 0, SEEK_CUR));
            fail_count++;
        }
        /* Commenting out do_some_work out seems to make the problem happen less often.*/
        do_some_work(fd);
        count++;
        memset(buffer, 0x39, sizeof(buffer));

    }
    close(fd);

    if(fail_count== 0)
        printf("Completed %d reads successfully\n", count);
    else{
        printf("Completed %d reads total fails at %d\n", count,fail_count);
    }

    return fail_count;
}