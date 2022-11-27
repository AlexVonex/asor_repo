#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {


	if (argc < 2) {
		 printf("ERROR: Se debe especeficar la ruta del archivo\n");
		 return -1;
	}

    int fd = open(argv[1], O_CREAT | O_RDWR, 00777);
   
    if(fd == -1){
        printf("ERROR: No se ha podido abrir el fichero.\n");
		 return -1;
    }
    else{
        //int fd2 = dup2(fd, 1);
        int fd3 = dup2(fd,2);
        int fd2 = dup2(fd, 1);

        printf("R a %s \n", argv[1]);
        char* c
        if(setuid(0) == -1) perror(c);
        

    }
    return 0;

}
