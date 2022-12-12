#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include  <fcntl.h>


int main(int argc, char ** argv) {

    if(argc < 2){
        printf("ERROR: Introduce el comando \n");
        return -1;
    }

    int salida =  mkfifo("tuberia", 0222);

    int fd = open("tuberia", O_WRONLY);

    write(fd, argv[1], strlen(argv[1]));

    close(fd);
    
    return 0;
}
