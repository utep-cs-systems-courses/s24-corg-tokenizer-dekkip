#include "history.h"
#include <stdio.h>
#include <stdlib.h>

List *init_history(){
  List *history = (List*)malloc(sizeof(List));
  history->root = NULL;
  return history;
}

void add_history(List *list, char *str){

  if (list == NULL) return;
  Item* newNode = (Item*)malloc(sizeof(Item));
  
  // copy the string to new memory location
  newNode->str = strdup(str);
  newNode->next = NULL;

  if (list->root == NULL) {
    list->root = newNode;
    newNode->id = 1;
    return;
  }

  // find the last node
  Item* lastNode = list->root;
  while (lastNode->next != NULL) {
    lastNode = lastNode->next;
  }

  lastNode->next = newNode;
  newNode->id = lastNode->id + 1;
}
  
char *get_history(List *list, int id){
  Item *head = list->root;
  
  if(head==NULL){
    return NULL;
  }
  
  while(head != NULL){
    if(head->id == id){
      printf("%s\n", head->str);
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


