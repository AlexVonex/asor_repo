#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <limits.h>

int main(){ 
    int s;

    printf("Numero maximo de enlaces: %d\n", fpathconf(s,_PC_LINK_MAX));
    printf("Tamano maximo de una ruta: %ld\n", fpathconf(s,_PC_PATH_MAX));
    printf("Tamano maximo de un fichero: %ld\n", fpathconf(s ,_PC_NAME_MAX));
    
   return 1;
}
