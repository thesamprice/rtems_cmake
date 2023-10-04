/*
 * Hello world example
 */
#include <rtems.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define NUMBER_NOOPS (50000000)
#define VALUE_TO_WRITE (0xff33)
#include "regtest.c"
#include <rtems/shell.h>
#include <rtems/untar.h>


#define FILENAME "core-cpu1.exe"
#define TEST_OFFSET 0x1b3d70   // Some arbitrary offset

#define BUFFER_SIZE 2048
#define STRESS_COUNT 100000   // Read 100k times


void SetupFileSystem();
int LSeekStressTest(int lock_interrupts);
int InterruptTest();
int lock_interrupts = 0;

rtems_task Init(
  rtems_task_argument ignored
)
{
    int fails_int = 0;
    int fails_no_int = 0;
    rtems_status_code sc = RTEMS_SUCCESSFUL;
    printf( "\nStarting interrupt fseek tests \n" );
    uint32_t read_value;
    uint32_t value_to_write = VALUE_TO_WRITE;
read_value = 0;
asm volatile ( 
        "addik r3, %1, 0\n\t"
        "addik r13, %2, 0\n\t"  // Move the immediate value to r13
        "testloopr3:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r13, r13, -1   \n\t"    // Subtract 1 from r13
        "bneid r13, testloopr3 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r3, 0   \n\t"    // Move the value from r3 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r3", "r13"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r3 is still %u\n", read_value);
    } else {
        printf("Failure: r3 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }


    TestRegs();
    InterruptTest();
    // SetupFileSystem();
    // int i = 0;
    // while(1){


    //     fails_int += LSeekStressTest(lock_interrupts = 0);
    //     printf("%03d Int Fail Count %3d No Int Fail %3d\n",i, fails_int, fails_no_int);

    //     fails_no_int += LSeekStressTest(lock_interrupts = 1);
    //     printf("%03d Int Fail Count %3d No Int Fail %3d\n",i, fails_int, fails_no_int);
    //     i += 1;
    // }

    printf( "\nTestDone\n" );
    exit( 0 );
}


int InterruptTest(){
    uint32_t value_to_write = 42;
    uint32_t read_value = 0;




    return 0;

}
