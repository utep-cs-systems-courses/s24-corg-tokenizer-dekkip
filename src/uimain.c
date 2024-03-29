
#include <stdio.h>
#include "tokenizer.h"
#include <string.h>
#include "history.h"

int main(){

  List *historyList = init_history();
  int userinput = 1;

  printf("Welcome to Lab 1: Tokenizer\n");
  while(userinput != 0){
    printf("Please enter an option: 1-input to tokenizer 2-history 3-lookup with id 0- quit\n");
    scanf("%d", &userinput);
    getchar();
    
    switch(userinput){

    case 1: //tokenizer + add to list
      printf("You picked option 1\n");
      printf("$ ");
      char* string[50];
      fgets(string, sizeof(string), stdin);
      printf("Your words, not mine: %s\n", string);
      
      char** tokens = tokenize(string);
      printf("Successfully tokenized: \n");
      print_tokens(tokens);
      free_tokens(tokens);

      add_history(historyList, string);
      printf("Successfully added to history! \n");
      break;

    case 2: //print history
      print_history(historyList);
      free_history(historyList);
      break;

    case 3: //get_history
      printf("Enter ID num of list item: ");
      int getID = 0;
      scanf("%d", &getID);

      printf("%d. %s \n", getID, get_history(historyList, getID));
      break;

    case 0:
      printf("Exiting...\n");
      break;
    }
  }
 
  printf("Have a nice day~\n"); 

  return 0;
}
