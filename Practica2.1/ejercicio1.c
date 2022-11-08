#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main(){
  char *codigoError;
  if (setuid(0) == -1) perror(codigoError);
	
  return 1;
}
