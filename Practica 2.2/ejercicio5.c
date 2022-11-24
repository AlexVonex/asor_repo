#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(){
    const char path[] = "/home/cursoredes/Practica2/ficheroej5.txt";
    /*O_RDONLY;
    O_WRONLY;
    O_RDWR;*/
    mode_t properties = 0645;
    int flags = O_CREAT;

    int abrir = open(path, flags, properties);

    printf("Resultado= %i\n" , abrir);
    return 0;
}
