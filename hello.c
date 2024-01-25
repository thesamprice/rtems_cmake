/*
 * Hello world example
 */
#include <rtems.h>
#include <stdlib.h>
#include <stdio.h>

#include <rtems/shell.h>
#include <rtems/rtl/dlfcn-shell.h>
#include <dlfcn.h>
#include <rtems/rtl/rap-shell.h>
#include <rtems/rtl/rtl-shell.h>
#include <rtems/untar.h>
#include <rtems/bdbuf.h>
#include <rtems/error.h>

void SetupFileSystem(void);
void add_dl_commands(void);
void shell_start(void);
rtems_task Init(
  rtems_task_argument ignored
)
{
  rtems_status_code sc = RTEMS_SUCCESSFUL;

  SetupFileSystem();
  add_dl_commands();
  shell_start();

  printf( "\nHello World\n" );
  exit( 0 );
}


void SetupFileSystem(void){
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

void add_dl_commands(void)
{
   rtems_shell_add_cmd("dlopen","misc","dynamic loader dlopen",shell_dlopen);
   rtems_shell_add_cmd("dlclose","misc","dynamic loader dlclose",shell_dlclose);
   rtems_shell_add_cmd("dlsym","misc","dynamic loader dlsym",shell_dlsym);
   rtems_shell_add_cmd("dlcall","misc","dynamic loader dlcall",shell_dlcall);

   rtems_shell_add_cmd("rap","misc","dynamic loader rap command",shell_rap);

   rtems_shell_add_cmd("rtl","misc","dynamic loader rtl command",rtems_rtl_shell_command);
}

void shell_start(void)
{
    rtems_status_code sc;

    printf("Starting shell....\n\n");

    sc = rtems_shell_init("shell0", 20 * 1024, 100, "/dev/console", 0, 1, NULL);
    if (sc != RTEMS_SUCCESSFUL)
    {
        printf("error: starting shell: %s (%d)\n", rtems_status_text(sc), sc);
    }
}