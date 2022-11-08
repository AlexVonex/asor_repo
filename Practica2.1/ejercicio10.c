#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <limits.h>
#include <pwd.h>

int main(){ 

    struct passwd *usuario;
    usuario = getpwuid(getuid());


    printf("UID real: %d\n", getuid());
    printf("UID efectivo: %d\n", geteuid());
    printf("Nombre de usuario: %s\n",usuario->pw_name);
    printf("Directorio home: %s\n", usuario->pw_dir);
    printf("Descripcion del usuario: %s\n", usuario->pw_gecos);
    
   return 1;
}
