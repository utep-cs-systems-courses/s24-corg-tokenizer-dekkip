#include <stdio.h>

int main(){

  char string [50];
  printf("$ ");
  scanf("%s", &string);
  printf("%s\n", &string); 

  return 0;
}