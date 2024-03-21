#include "tokenizer.h"
#include <stdlib.h>
#include <stdio.h>

int space_char(char c){
  if((c == ' ') || (c=='\t'))
    return 1;
  return 0;
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
  while((*token != ' ') || (*token != '\0')){
    token++;
  }
  return token;
}

int count_tokens(char *str){
  int length = 0;
  while (str[length] != '\0'){
    length++;
  }
  int count = 0;
  for (int i = 0; i < length; i++){
    printf("%c ", str[i]);
    if(space_char(str[i])){
      printf("space");
      count +=1 ;
      printf("%d", count);
    }
  }
  count += 1;
  printf("this is %d", count);
  return count;
}

char *copy_str(char *inStr, short len){
  int length = (int)len;
  char *newStr = (char*)malloc((length+1)*(sizeof(char)));
  for(int i=0; i < len; i++){
    newStr[i] = inStr[i];
  }
  return newStr;
}

char **tokenize(char* str){
    int num_tokens = count_tokens(str);
    char **tokens = (char**)malloc((num_tokens+1)*sizeof(char*));
    
    char *token = token_start(str);
    int i = 0;
    while(token){
      char *terminator = token_terminator(token);
      size_t token_length = terminator - token;
      tokens[i] = copy_str(token, token_length);
      tokens[i][token_length] = '\0';
      i++;
      token = token_start(terminator);
    }
    //token[num_tokens] = NULL;
    return tokens;
}

void print_tokens(char **tokens){
  int i = 0;
  char *token = tokens[i];
  while(token){
    printf("%s \n", tokens[i]);
    i++;
    token = tokens[i];
  }
}

void free_tokens(char **tokens){
  int i = 0;
  char *token = tokens[i];
  while(token){
    free(tokens[i]);
    i++;
    token = tokens[i];
  }
}
