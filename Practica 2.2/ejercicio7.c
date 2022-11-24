#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(){
    const char path[] = "/home/cursoredes/Practica2/ficheroej7.txt";
    /*O_RDONLY;
    O_WRONLY;
    O_RDWR;*/
    mode_t quita = umask(0027);
    mode_t properties = 0777;
    int flags = O_CREAT;

    int abrir = open(path, O_CREAT | O_RDONLY, properties);

    mode_t ultimo = umask(quita);

    printf("Resultado= %i\n" , ultimo);
    return 0;
}
