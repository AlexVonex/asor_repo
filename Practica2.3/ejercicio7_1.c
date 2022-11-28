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
        printf("Falta comando \n");
    }
    int salida = execvp(argv[1], argv + 1);

    if(salida == -1){
        printf("error \n");
        return -1;
    }
    else{
        printf("El comando termino de ejecutarse. \n");
    }
   
    return 1;
}
