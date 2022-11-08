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

const int NUM = 1000000;

int main(){ 
    time_t time;
    struct timeval tv;

    int microseg = gettimeofday(&tv, NULL);
    long inicio = tv.tv_usec;
    
    int i;
    for(i = 0; i < NUM; i++){
    }

    int microsegpost = gettimeofday(&tv, NULL);
    long final = tv.tv_usec;
    
    printf("Hora en microsegundos: %d\n", (final - inicio));

   return 1;
}
