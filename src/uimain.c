#include <stdio.h>
#include "tokenizer.h"

int main(){

  char string [50];
  printf("$ ");
  gets(string);
  printf("%s\n", string);

  int count = count_tokens(string);
  printf("%d ", string);
  
  // print_tokens(tokenize(string));
  
  return 0;
}
