#include <unistd.h>
#include <stdio.h>

int main() {
	printf("Max argumento: %li\n", sysconf(_SC_ARG_MAX));
	printf("Max hijos: %li\n", sysconf(_SC_CHILD_MAX));
	printf("Max ficheros: %li\n", sysconf(_SC_OPEN_MAX));
	return 0;
}
