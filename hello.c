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

/****   TEST r19 *********/
read_value = 0;
printf("Starting Reg r19 \n");
asm volatile ( 
        "addik r4, r19, 0\n\t"
        "addik r19, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr19:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr19 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r19, 0   \n\t"    // Move the value from r22 to read_value
        "addik r19, r4, 0\n\t"
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        :  "r4","r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r19 is still %u\n", read_value);
    } else {
        printf("Failure: r19 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }

/****   TEST r19 *********/
read_value = 0;
printf("Starting Reg r20 \n");
asm volatile ( 
        "addik r4, r20, 0\n\t"
        "addik r20, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr20:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr20 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r20, 0   \n\t"    // Move the value from r22 to read_value
        "addik r20, r4, 0\n\t"
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        :  "r4","r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r20 is still %u\n", read_value);
    } else {
        printf("Failure: r20 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
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
