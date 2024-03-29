#include "history.h"
#include <stdio.h>


List *init_history(){
  char *string = "List";
  Item root = {.id = 0, .str = string};
}

void add_history(List *list, char *str){

  char* head = list;
  while(*head != NULL){
    if(head.next == NULL){
      int idnum = *head.id;
      int newID = idnum + 1;
      Item node = {.id = newID, .str = str};
      *head.next = node;
      return;
    }
    else{
      head = head.next;
    }
  }
}

char *get_history(List *list, int id){

    return 'a';
  }

void print_history(List *list){



  }

void free_history(List *list){



  }


