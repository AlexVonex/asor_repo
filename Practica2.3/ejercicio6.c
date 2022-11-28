#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/time.h>

void atributos(char *text){
    pid_t pid = getpid();
    printf("%s PID: %d \n", text, pid);
    
    pid_t ppid = getppid();
    printf("%s PPID: %d \n", text, ppid);

    pid_t gpid = getpgid(pid);
    printf("%s GPID: %d \n", text, gpid);

    pid_t sid = getsid(pid);
    printf("%s SID: %d \n", text, sid);

    struct rlimit limit;
    int x = getrlimit(RLIMIT_NOFILE, &limit);

    
    printf("%s LIMIT: %li \n",text, limit.rlim_max);

    size_t size = 4096;
    char buff =  malloc(sizeof(char)(size + 1));
    char *ruta = getcwd(buff, size + 1);
    printf("%s RUTA: %s \n",text, ruta);
    
}

int main(/int argc, char * argv*/) {

    
    pid_t pid = fork();
    
    if(pid == 0){
        pid_t sesion = setsid();
        //const char *ruta = "/tmp";
        int directorio = chdir("/tmp");
        printf("Hijo %i (padre: %i)\n", getpid(), getppid());
        atributos("Hijo");
    }
    else if(pid > 0){
        printf("Padre %i (hijo: %i)\n", getpid(), pid);
        atributos("Padre");
    }
    else{
        exit(1);
    }
    return 1;
}
