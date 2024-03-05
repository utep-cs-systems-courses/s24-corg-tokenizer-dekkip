#inlcude "tokenizer.h"

int space_char(char c){
  if(c == ' ')
    return true;
  return false;
}

int non_space_char(char c){
  return !space_char(c);
}

char *token_start(char *str){
  char *p = str;
  p++;
  return p;
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
