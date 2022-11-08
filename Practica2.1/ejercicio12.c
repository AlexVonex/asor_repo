#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <limits.h>
#include <pwd.h>
#include <time.h>
#include <sys/time.h>

int main(){ 
   
    printf("Hora en segundos: %li\n", time(NULL));

   return 1;
}
