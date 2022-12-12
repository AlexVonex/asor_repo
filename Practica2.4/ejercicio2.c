#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <errno.h>

int main(int argc, char ** argv) {

    if(argc < 2){
            printf("ERROR: Introduce el comando \n");
    }

    int fd_p_h[2];
    int fd_h_p[2];
    pipe(fd_p_h);
    pipe(fd_h_p);
    char* cont;
    int i = 0;
    char *text;
    char *text2;
    pid_t pid = fork();

    if(pid == 0){ //Hijo
        close(fd_p_h[1]);       //extremo de escritura
        close(fd_h_p[0]);       //extremo de lectura

        for(; i < 10; i++){
            ssize_t bytes = read(fd_p_h[0], text , 255); //Leer de la entrada estandar
            text[bytes] = '\0';
            printf("HIJO Recibido: %s \n", text); //Escribir a la salida estandar
            sleep(1);
            if(i == 9){
                cont = 'q';
            }
            write(fd_h_p[1], &cont, 1); //Escrbir en la tuberia h_p
        }        
    }
    else if(pid > 0){ //Padre
        close(fd_p_h[0]);       //extremo de lectura
        close(fd_h_p[1]);       //extremo de escritura
       

        while(cont != 'q'){
            printf("%s\n", "[PADRE] Mensaje: ");
            ssize_t bytes = read(0, text2, 255);
            //text2[bytes] = '\0';
            write(fd_p_h[1], text2, 255);
            read(fd_h_p[0], &cont, 1);
        }
        //wait(NULL);
        printf("10. \n");
    }
    else{
        perror("ERROR");
        return 0;
    }

    return 0;
}
