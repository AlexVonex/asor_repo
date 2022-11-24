#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include <time.h>

int main(int argc, char **argv) {

	if (argc < 2) {
		 printf("ERROR en especificar ruta \n");
		 return -1;
	}

	struct stat buff;

	int st = stat(argv[1], &buff);

if (st == -1) {
		printf("No existe \n");
		return -1;
	}

	printf("MAJOR: %li\n", (long) minor(buff.st_dev));
	printf("MINOR: %li\n", (long) major(buff.st_dev));

	//nodo
	printf("I-Node: %li\n",buff.st_ino);

	//Tipo de archivo
	printf("MODE: %i\n",buff.st_mode);
    mode_t mode = buff.st_mode;

	if (S_ISLNK(mode)){
		printf("%s es un enlace simbólico.\n", argv[1]);
	} else if (S_ISREG(mode)) {
		printf("%s es un archivo ordinario.\n", argv[1]);
	} else if (S_ISDIR(mode)) {
		printf("%s es un directorio.\n", argv[1]);
	}

	//Hora A
	time_t ta = buff.st_atime;

	struct tm *tm1= localtime(&ta);
    printf("Últime acceso (A): %d:%d\n", tm1->tm_hour, tm1->tm_min);

	//M
	time_t t2 = buff.st_mtime;

	struct tm *tm2= localtime(&t2);

	printf("Últime acceso (M): %d:%d\n", tm2->tm_hour, tm2->tm_min);

	//HoraC
	time_t tc = buff.st_ctime;

	struct tm *tm3= localtime(&tc);

	printf("Últime acceso (C): %d:%d\n", tm3->tm_hour, tm3->tm_min);

	return 0;
}
