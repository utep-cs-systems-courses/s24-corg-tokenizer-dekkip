#include "history.h"
#include <stdio.h>
#include <stdlib.h>

List *init_history(){
  List *history = (List*)malloc(sizeof(List));
  history->root = NULL;
  return history;
}

void add_history(List *list, char *str){

  Item* head = list->root;
  if(head == NULL){
    list->root = (Item*)malloc(sizeof(Item));
    list->root->id = 0;
    list->root->str = str;
    list->root->next = NULL;
    return;
   }

  while(head->next != NULL){
    head = head->next;
  }

  head->next = (Item*)malloc(sizeof(Item));
  head->next->id = head->id+1;
  head->next->str = str;
  head->next->next = NULL;
}

char *get_history(List *list, int id){
  Item *head = list->root;
  
  if(head==NULL){
    return NULL;
  }
  
  while(head != NULL){
    if(head->id == id){
      return head->str;
    }
    head = head->next;
  }
  return NULL;
}

void print_history(List *list){
  Item *head = list->root;
  
  while(head != NULL){
    printf("%d. %s \n", head->id, head->str);
    head = head->next;
  }

}

void free_history(List *list){
  Item *head = list->root;
  Item *neck = head->next;

  while(head->next != NULL){
    free(head);
    head = neck;
    neck = head->next;
  }
}


