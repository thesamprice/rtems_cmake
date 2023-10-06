/*
 * Hello world example
 */
#include <rtems.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdint.h>
#include <rtems/shell.h>
#include <rtems/untar.h>


#define FILENAME "core-cpu1.exe"
#define TEST_OFFSET 0x1b3d70   // Some arbitrary offset

#define BUFFER_SIZE 2048
#define STRESS_COUNT 100000   // Read 100k times


int Int64Test(int lock_interrupts);


rtems_task Init(
  rtems_task_argument ignored
)
{
    int fails_int = 0;
    int fails_no_int = 0;
    rtems_status_code sc = RTEMS_SUCCESSFUL;
    printf( "\nStarting interrupt fseek tests \n" );
    printf("Size of off_t is %d\n",sizeof(off_t));


    int i = 0;
    int lock_interrupts;
    Int64Test(lock_interrupts = 1);

    while(1){


        fails_int += Int64Test(lock_interrupts = 0);
        printf("%03d Int Fail Count %3d No Int Fail %3d\n",i, fails_int, fails_no_int);

        i += 1;
    }

    printf( "\nTestDone\n" );
    exit( 0 );
}
rtems_interrupt_lock_context lock_contex;
rtems_interrupt_lock interrupt_lock;

int64_t truth_divide[STRESS_COUNT];
int64_t truth_mod[STRESS_COUNT];
int64_t truth_mul[STRESS_COUNT];
int Int64Test(int lock_interrupts) {
    int fd;
    uint32_t value;
    int count = 0;
    int fail_count = 0;

    volatile int64_t size;
    volatile int64_t div_check;
    volatile int64_t mod_check;
    volatile int64_t mul_check;
    for (int i = 0; i < STRESS_COUNT; i++) {
        size = TEST_OFFSET*i;

        if(lock_interrupts){

            rtems_interrupt_lock_acquire(interrupt_lock, &lock_contex);
            div_check =  size / 128;
            mod_check = size % 128;
            mul_check = size * 128;

            truth_divide[i] = div_check;
            truth_mod[i] = mod_check;
            truth_mul[i] = mul_check;
            rtems_interrupt_lock_release(interrupt_lock, &lock_contex);

        }
        else{
            // rtems_interrupt_lock_acquire(interrupt_lock, &lock_contex);
            div_check =  size / 128;
            mod_check = size % 128;
            mul_check = size * 128;
            // rtems_interrupt_lock_release(interrupt_lock, &lock_contex);

            if(truth_divide[i] != div_check){
                printf("%8d div fail: truth %ld got %ld\n",i, truth_divide[i], div_check);
                fail_count++;
            }
            if(truth_mod[i] != mod_check){
                printf("%8d mod fail: truth %ld got %ld\n",i, truth_mod[i], mod_check);
                fail_count++;
            }
            if(truth_mul[i] != mul_check){
                printf("%8d mul fail: truth %ld got %ld\n",i, truth_mul[i], mul_check);
                fail_count++;
            }
            count++;
        }

    }

    if(fail_count== 0)
        printf("Completed %d ops successfully\n", count);
    else{
        printf("Completed %d ops total fails at %d\n", count,fail_count);
    }

    return fail_count;
}