# Compiling the software
```bash
# Clone down test code and checkout test branch
git clone git@github.com:thesamprice/rtems_cmake.git
cd rtems_cmake
git checkout lseek_stress_test
 
# Modify CMakeLists.txt for proper paths or set env variables
export RTEMS_PATH=$HOME/opt/rtems/6
export RTEMS_BSP_NAME=kcu105
 
# Build the image
mkdir build
cd build
cmake ..
make

```

# Load bitfile
```bash
xsdb
connect
target X
fpga kcu105-stock.bit
```

# Loading test image
Assuming kcu105 is already programmed with bitfile, next load the elf file that was just built.
```
cd rtems_cmake
xsdb load-cpu0-elf.tcl  build/fseek_stress_test
```


# Debug notes 
The init.c has been configured with a higher clock rate to cause this error to happen more often.
`#define CONFIGURE_MICROSECONDS_PER_TICK (100)`


After running for a while you will see failures only occur when the interrupts are enabled, and not when they are disabled.

```
237 Int Fail Count 14476 No Int Fail   0
Mismatched value at iteration 964. Expected: 0x7cf5b, Got: 0x3cf5b : fpos 1787248
Mismatched value at iteration 4976. Expected: 0x7cf5b, Got: 0x7cf57 : fpos 1787248
Mismatched value at iteration 5320. Expected: 0x7cf5b, Got: 0x7cf53 : fpos 1787248
Mismatched value at iteration 5487. Expected: 0x7cf5b, Got: 0x3cf5b : fpos 1787248
Mismatched value at iteration 8454. Expected: 0x7cf5b, Got: 0x3cf5b : fpos 1787248
Completed 100000 reads total fails at 5
238 Int Fail Count 14481 No Int Fail   0
```