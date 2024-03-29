
#include "tokenizer.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

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
  while(space_char(*p)){
    p+=1;
    }
  return p;
}

char *token_terminator(char *token){
  while(non_space_char(*token)){
    token+= 1;
  }
  return token;
}

int count_tokens(char *str){
  int count = 0;
  char *pointer = str;
  while (*pointer != '\0'){
    pointer = token_start(pointer);
    if(*pointer == '\0' || !isalnum(*pointer)){
      break;
    }
    //printf("token_start: %c\n", *pointer);
    if(*pointer){
      pointer = token_terminator(pointer);
      // printf("token_terminator: %c\n", *pointer);
      count += 1;
    }
  }
  //printf("count: %d \n", count);
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
    printf("num_tokens: %d\n", num_tokens);
    
    char **tokens = (char**)malloc((num_tokens+1)*sizeof(char*));
    char *token = token_start(str);
    //printf("token: %c\n", *token);
    int i = 0;
    
    while(*token != '\0' && isalnum(*token)){
      char *terminator = token_terminator(token);
      size_t token_length = terminator - token;
      tokens[i] = copy_str(token, token_length);
      tokens[i][token_length] = '\0';
      i++;
      //printf("token before: %c \n",*token);
      token = token_start(terminator);
      //printf("token after: %c\n", *token);
    }

    char* null = NULL;
    tokens[num_tokens] = null;
    
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
  for (int i = 0; tokens[i] != NULL; i++){
    free(tokens[i]);
  }
  free(tokens);
}
