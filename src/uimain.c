
#include <stdio.h>
#include "tokenizer.h"
#include <string.h>

int main(){

  printf("$ ");
  char* string[50];
  fgets(string, sizeof(string), stdin);
  printf("%s \n",string);

  // printf("count: %d \n", count_tokens(string));
  char** tokens = tokenize(string);
  
  return 0;
}
