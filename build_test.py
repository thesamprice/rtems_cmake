test = """

/****   TEST {regName} *********/
read_value = 0;
printf("Starting Reg {regName} \\n");
asm volatile ( 
        "addik {regName}, %1, 0\\n\\t"
        "addik r3, %2, 0\\n\\t"  // Move the immediate value to r3
        "testloop{regName}:                 \\n\\t"    // Label 1
        "nop                \\n\\t"    // No operation
        "addik r3, r3, -1   \\n\\t"    // Subtract 1 from r3
        "bneid r3, testloop{regName} \\n\\t"    // If result is not zero, branch to label testloop
        "addik %0, {regName}, 0   \\n\\t"    // Move the value from r22 to read_value
        : "=r" (read_value)
        : "r" (value_to_write), "r" (NUMBER_NOOPS)
        : "{regName}", "r3"
    );
    if (read_value == VALUE_TO_WRITE) {{
        printf("Success: {regName} is still %u\\n", read_value);
    }} else {{
        printf("Failure: {regName} is %u, expected %u\\n", read_value, VALUE_TO_WRITE);
    }}
"""

testNames = []
#testNames += ["r1"]
testNames += ["r2"]
for x in range(4,14):
    testNames += [f"r{x}"]
testNames += ["r14"]
testNames += ["r15"]

for x in range(16,19):
    testNames += [f"r{x}"]
#testNames += ["r19"] # doesnt like r19
# testNames += ["r20"] # doesnt is pic register?


for x in range(21,32):
    testNames += [f"r{x}"]

#testNames += ["r1"]
print("void TestRegs(){\n")
print("""
      uint32_t read_value = 0x0;
      uint32_t value_to_write = VALUE_TO_WRITE;
""")
for regName in testNames:
    print(test.format(regName=regName))
print("}\n")