# Example of microblaze error of dynamic loader using a cpp file

### Compile process / launch qemu
```
mkdir build
cd build
cmake ..
make
cd ..

./launch_qemu.sh
```

### Error output
```
rtl trace unresolved

shell0 [/] # rtl trace unresolved
shell0 [/] #
shell0 [/] #
shell0 [/] # ls
dev                 etc                 keep.txt            object_test.cpp.o
shell0 [/] # dlopen object_test.cpp.o
rtl: unresolv: block-alloc 0x800c4204 (0x800d9294)
rtl: unresolv: add: object_test.cpp.o(s:1) -> fopen
rtl: unresolv: add: object_test.cpp.o(s:1) -> fgets
rtl: unresolv: add: object_test.cpp.o(s:1) -> fclose
rtl: unresolv: add: object_test.cpp.o(s:1) -> sscanf
rtl: unresolv: add: object_test.cpp.o(s:6) ->
rtl: unresolv: add: object_test.cpp.o(s:6) ->
rtl: unresolv: add: object_test.cpp.o(s:6) ->
rtl: unresolv: add: object_test.cpp.o(s:6) ->
rtl: unresolv: global resolve
rtl: unresolv: lookup: 1: fopen
rtl: unresolv: lookup: 2: fgets
rtl: unresolv: lookup: 3: fclose
rtl: unresolv: lookup: 4: sscanf
rtl: unresolv: lookup: 5:
rtl: unresolv: archive lookup: 1: fopen
RTL Unresolved data:
   0: 1:  name:   1 refs:   1: flags:0000 fopen (6)
   2: 1:  name:   2 refs:   1: flags:0001 fgets (6)
   4: 1:  name:   3 refs:   1: flags:0001 fclose (7)
   6: 1:  name:   4 refs:   1: flags:0001 sscanf (7)
   8: 1:  name:   5 refs:   4: flags:0001  (1)
rtl: obj: unresolved: dep: object_test.cpp.o is unresolved
handle: 0x800cf638 has unresolved externals
shell0 [/] #
```

```ctrl+a,x``` to quit qemu

Note im not concerned about the unresolved symbols that have names.
The no name symbol I am not sure how to correct.
