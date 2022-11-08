#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <limits.h>

int main(/int argc, int argv/){ 

    printf("UID real: %d\n", getuid());
    printf("UID efectivo: %d\n", geteuid());
    
   return 1;
}
