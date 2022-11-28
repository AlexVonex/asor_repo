#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/time.h>

int main(int argc, char **argv) {

    if(argc < 2){
        printf("Introduce el comando \n");
    }
    int salida = system(argv[1]);

    if(salida == -1){
        printf("error \n");
        return -1;
    }
    else{
        printf("El comando termino de ejecutarse. \n");
    }
   
    return 1;
}
