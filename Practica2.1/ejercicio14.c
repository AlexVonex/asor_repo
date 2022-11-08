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
    time_t t = time(NULL);
    struct tm *a = localtime(&t); 
    printf("Año: %d\n", 1900 + a->tm_year);

   return 1;
}
