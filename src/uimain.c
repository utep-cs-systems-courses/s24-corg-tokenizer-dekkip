#include <stdio.h>
#include "tokenizer.h"
#include <string.h>

int main(){

  char string [50];
  printf("$ ");
  fgets(string, 50, stdin);
  if(string[strlen(string)-1] == '\n'){
    string[strlen(string) -1] = '\0';
    }
  
  printf("%s\n", string);

  printf("hii");
  int count = count_tokens(string);
  printf("%d ", count);
  
  // print_tokens(tokenize(string));
  
  return 0;
}
