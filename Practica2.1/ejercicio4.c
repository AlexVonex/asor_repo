#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/utsname.h>
#include <sys/types.h>


int main(){
  struct utsname sistema;
  if (uname &sistema) == -1){
     printf("ERROR(%d): %s\n", errno, strerror(errno));
     return -1;
	} else {
    printf("Nombre del Sistema: %s\n", sistema.sysname);
    printf("Nodename: %s\n", sistema.nodename);
    printf("Release: %s\n", sistema.release);
    printf("Version: %s\n", sistema.version);
    printf("Machine: %s\n", sistema.machine);
  }
  return 1;
}
