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
    const struct tm *a = localtime(&t); 
    char outstr[200];
    char outstr2[200];
    strftime(outstr, sizeof(outstr), "%A, %d de %B de", a);
    strftime(outstr2, sizeof(outstr2), ", %H:%M", a);
    printf(" \%s", outstr);
    printf(" \%d", 1900 + a->tm_year);
    printf(" \%s\n", outstr2);

   return 1;
}
