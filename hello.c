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

rtems_task Init(
  rtems_task_argument ignored
)
{
    rtems_status_code sc = RTEMS_SUCCESSFUL;

  SetupFileSystem();
LSeekStressTest();


  printf( "\nHello World\n" );
  exit( 0 );
}


void SetupFileSystem(){
    extern const unsigned char config_tar[];
    extern const size_t config_tar_size;
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
#define TEST_OFFSET 0x1000   // Some arbitrary offset
#define BUFFER_SIZE 2048
#define STRESS_COUNT 10000   // Read 10k times

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
    uint32_t EXPECTED_VALUE = 0x0;

    fd = open(FILENAME, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        exit(1);
    }

    for (int i = 0; i < STRESS_COUNT; i++) {
        lseek(fd, TEST_OFFSET, SEEK_SET);
        if (read(fd, buffer, BUFFER_SIZE) != BUFFER_SIZE) {
            perror("Failed to read from file");
            close(fd);
            exit(1);
        }



        memcpy(&value, buffer, sizeof(value));

        if(i == 0){
          EXPECTED_VALUE = value;
        }

        if (value != EXPECTED_VALUE) {
            printf("Mismatched value at iteration %d. Expected: 0x%x, Got: 0x%x\n",
                   i, EXPECTED_VALUE, value);
            break;
        }

        count++;

        // Do some other activity every 100 reads
        if (i % 100 == 0) {
            do_some_work(fd);
        }
    }

    printf("Completed %d reads successfully\n", count);

    close(fd);
    return 0;
}