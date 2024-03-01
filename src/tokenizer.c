#inlcude "tokenizer.h"
#inlcude <ctype.h>

int space_char(char c){
  return isspace(c);
}

int non_space_char(char c){
  return !isspace(c);
}

int *token_start(char *str){

  return 0;
}

char *token_terminator(char *token){

  return 'c';
}

int count_tokens(char *str){
  return 0;
}

char *copy_str(char *inStr, short len){

  return 'c';
}

char **tokenize(char* str){
  return 'c';
}

void print_tokens(char **tokens){

}

void free_tokens(char **tokens){

}
