#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv){
  
  printf("Hello, world! :)\n");
  printf("This program was launched as: \033[1;37m%s\033[0m and was invoked with: \033[1;37m%d\033[0m extra arguments.\n", argv[0], argc-1);
  
  return EXIT_SUCCESS;

}
