void TestRegs(){


      uint32_t read_value = 0x0;
      uint32_t value_to_write = VALUE_TO_WRITE;



/****   TEST r2 *********/
read_value = 0;
printf("Starting Reg r2 \n");
asm volatile ( 
        "addik r2, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr2:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr2 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r2, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r2", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r2 is still %u\n", read_value);
    } else {
        printf("Failure: r2 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }



/****   TEST r4 *********/
read_value = 0;
printf("Starting Reg r4 \n");
asm volatile ( 
        "addik r4, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr4:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr4 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r4, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r4", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r4 is still %u\n", read_value);
    } else {
        printf("Failure: r4 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }



/****   TEST r5 *********/
read_value = 0;
printf("Starting Reg r5 \n");
asm volatile ( 
        "addik r5, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr5:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr5 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r5, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r5", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r5 is still %u\n", read_value);
    } else {
        printf("Failure: r5 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }



/****   TEST r6 *********/
read_value = 0;
printf("Starting Reg r6 \n");
asm volatile ( 
        "addik r6, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr6:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr6 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r6, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r6", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r6 is still %u\n", read_value);
    } else {
        printf("Failure: r6 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }



/****   TEST r7 *********/
read_value = 0;
printf("Starting Reg r7 \n");
asm volatile ( 
        "addik r7, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr7:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr7 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r7, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r7", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r7 is still %u\n", read_value);
    } else {
        printf("Failure: r7 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }



/****   TEST r8 *********/
read_value = 0;
printf("Starting Reg r8 \n");
asm volatile ( 
        "addik r8, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr8:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr8 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r8, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r8", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r8 is still %u\n", read_value);
    } else {
        printf("Failure: r8 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }



/****   TEST r9 *********/
read_value = 0;
printf("Starting Reg r9 \n");
asm volatile ( 
        "addik r9, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr9:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr9 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r9, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r9", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r9 is still %u\n", read_value);
    } else {
        printf("Failure: r9 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }



/****   TEST r10 *********/
read_value = 0;
printf("Starting Reg r10 \n");
asm volatile ( 
        "addik r10, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr10:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr10 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r10, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r10", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r10 is still %u\n", read_value);
    } else {
        printf("Failure: r10 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }



/****   TEST r11 *********/
read_value = 0;
printf("Starting Reg r11 \n");
asm volatile ( 
        "addik r11, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr11:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr11 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r11, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r11", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r11 is still %u\n", read_value);
    } else {
        printf("Failure: r11 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }



/****   TEST r12 *********/
read_value = 0;
printf("Starting Reg r12 \n");
asm volatile ( 
        "addik r12, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr12:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr12 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r12, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r12", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r12 is still %u\n", read_value);
    } else {
        printf("Failure: r12 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }



/****   TEST r13 *********/
read_value = 0;
printf("Starting Reg r13 \n");
asm volatile ( 
        "addik r13, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr13:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr13 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r13, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r13", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r13 is still %u\n", read_value);
    } else {
        printf("Failure: r13 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }



/****   TEST r15 *********/
read_value = 0;
printf("Starting Reg r15 \n");
asm volatile ( 
        "addik r15, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr15:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr15 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r15, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r15", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r15 is still %u\n", read_value);
    } else {
        printf("Failure: r15 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }



/****   TEST r16 *********/
read_value = 0;
printf("Starting Reg r16 \n");
asm volatile ( 
        "addik r16, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr16:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr16 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r16, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r16", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r16 is still %u\n", read_value);
    } else {
        printf("Failure: r16 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }



/****   TEST r17 *********/
read_value = 0;
printf("Starting Reg r17 \n");
asm volatile ( 
        "addik r17, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr17:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr17 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r17, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r17", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r17 is still %u\n", read_value);
    } else {
        printf("Failure: r17 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }



/****   TEST r18 *********/
read_value = 0;
printf("Starting Reg r18 \n");
asm volatile ( 
        "addik r18, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr18:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr18 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r18, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r18", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r18 is still %u\n", read_value);
    } else {
        printf("Failure: r18 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }



/****   TEST r21 *********/
read_value = 0;
printf("Starting Reg r21 \n");
asm volatile ( 
        "addik r21, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr21:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr21 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r21, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r21", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r21 is still %u\n", read_value);
    } else {
        printf("Failure: r21 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }



/****   TEST r22 *********/
read_value = 0;
printf("Starting Reg r22 \n");
asm volatile ( 
        "addik r22, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr22:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr22 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r22, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r22", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r22 is still %u\n", read_value);
    } else {
        printf("Failure: r22 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }



/****   TEST r23 *********/
read_value = 0;
printf("Starting Reg r23 \n");
asm volatile ( 
        "addik r23, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr23:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr23 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r23, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r23", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r23 is still %u\n", read_value);
    } else {
        printf("Failure: r23 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }



/****   TEST r24 *********/
read_value = 0;
printf("Starting Reg r24 \n");
asm volatile ( 
        "addik r24, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr24:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr24 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r24, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r24", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r24 is still %u\n", read_value);
    } else {
        printf("Failure: r24 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }



/****   TEST r25 *********/
read_value = 0;
printf("Starting Reg r25 \n");
asm volatile ( 
        "addik r25, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr25:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr25 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r25, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r25", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r25 is still %u\n", read_value);
    } else {
        printf("Failure: r25 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }



/****   TEST r26 *********/
read_value = 0;
printf("Starting Reg r26 \n");
asm volatile ( 
        "addik r26, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr26:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr26 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r26, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r26", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r26 is still %u\n", read_value);
    } else {
        printf("Failure: r26 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }



/****   TEST r27 *********/
read_value = 0;
printf("Starting Reg r27 \n");
asm volatile ( 
        "addik r27, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr27:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr27 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r27, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r27", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r27 is still %u\n", read_value);
    } else {
        printf("Failure: r27 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }



/****   TEST r28 *********/
read_value = 0;
printf("Starting Reg r28 \n");
asm volatile ( 
        "addik r28, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr28:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr28 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r28, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r28", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r28 is still %u\n", read_value);
    } else {
        printf("Failure: r28 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }



/****   TEST r29 *********/
read_value = 0;
printf("Starting Reg r29 \n");
asm volatile ( 
        "addik r29, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr29:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr29 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r29, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r29", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r29 is still %u\n", read_value);
    } else {
        printf("Failure: r29 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }



/****   TEST r30 *********/
read_value = 0;
printf("Starting Reg r30 \n");
asm volatile ( 
        "addik r30, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr30:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr30 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r30, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r30", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r30 is still %u\n", read_value);
    } else {
        printf("Failure: r30 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }



/****   TEST r31 *********/
read_value = 0;
printf("Starting Reg r31 \n");
asm volatile ( 
        "addik r31, %1, 0\n\t"
        "addik r3, %2, 0\n\t"  // Move the immediate value to r3
        "testloopr31:                 \n\t"    // Label 1
        "nop                \n\t"    // No operation
        "addik r3, r3, -1   \n\t"    // Subtract 1 from r3
        "bneid r3, testloopr31 \n\t"    // If result is not zero, branch to label testloop
        "addik %0, r31, 0   \n\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "r31", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {
        printf("Success: r31 is still %u\n", read_value);
    } else {
        printf("Failure: r31 is %u, expected %u\n", read_value, VALUE_TO_WRITE);
    }

}

