RTEMS_PATH=$HOME/opt/rtems/6
$RTEMS_PATH/bin/qemu-system-microblazeel \
-no-reboot \
-M microblaze-fdt-plnx \
-m 16 \
-serial mon:stdio \
-serial pty \
-serial pty \
-display none \
-dtb qemu/kcu105.dtb \
-kernel build/file_system_test
