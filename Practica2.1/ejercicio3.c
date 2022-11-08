#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>


int main(){
  int i=0;
  while(i<255){
    printf("ERROR(%d): %s\n", i, strerror(i));
    i++;
  }
  return 1;
}
