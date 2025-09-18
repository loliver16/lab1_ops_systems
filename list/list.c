// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

list_t *list_alloc() { 
  list_t* mylist =  (list_t *) malloc(sizeof(list_t)); 

  if (mylist == NULL){
    return NULL;
  }

  mylist->head = NULL;
  return mylist;
}

void list_free(list_t *l) {
  if (l == NULL){
    return;
  }

  node_t* curr = l->head;

  while (curr != NULL){
    node_t *next = curr->next;
    curr->next = NULL;
    free(curr);
    curr = next;
  }

  l->head = NULL;
  free(l);
}

void list_print(list_t *l) {
  if (l == NULL){
    return;
  }

  if (l->head == NULL) {
    return;
  }
  
  node_t* curr = l->head;

  while (curr != NULL){
    printf("%d", curr->value);
    fflush(stdout);
    curr = curr->next;
  }
}

char * listToString(list_t *l) {
  if (l == NULL){
    return;
  }
  
  char *buf = (char *)malloc(10240);
  if (!buf) return NULL;
  buf[0] = '\0';
  char tbuf[32];

	node_t* curr = l->head;
  
  while (curr != NULL) {
    sprintf(tbuf, "%d->", curr->value);
    curr = curr->next;
    strcat(buf, tbuf);
  }
  strcat(buf, "NULL");
  return buf;
}

int list_length(list_t *l) { 
  if (l == NULL){
    return 0;
  }
  
  node_t *curr = l->head;
  int length_count = 0;

  while (curr != NULL){
    length_count += 1;
    curr = curr->next;
  }

  return length_count;
}

void list_add_to_back(list_t *l, elem value) {
     if(l == NULL){
      return;
     }

     node_t *new_node = (node_t *) getNode(value);
     
     if(new_node == NULL){
      return;
     }

     if(l->head == NULL){
      l->head = new_node;
      return;
     }
     
     node_t *curr = l->head;

     while (curr->next != NULL){
      curr = curr->next;
     }

     curr->next = new_node;
}
void list_add_to_front(list_t *l, elem value) {
     if (l == NULL){
      return;
     }

     node_t *cur_node = (node_t *) getNode(value);
     if (cur_node == NULL){
      return;
     }
    
     /* Insert to front */
     node_t *head = l->head;  // get head of list
     cur_node->next = head;
     l->head = cur_node;
}

node_t * getNode(elem value) {
  node_t *mynode;

  mynode = (node_t *) malloc(sizeof(node_t));
  if (mynode == NULL){
    return NULL;
  }

  mynode->value = value;
  mynode->next = NULL;

  return mynode;
}

void list_add_at_index(list_t *l, elem value, int index) {
  if (l == NULL || index < 1) {
    return;
  }
  
  int count = 1;
  node_t *new_node = (node_t *) getNode(value);
  node_t* curr = l->head;
  
  if (index == 1){
    new_node->next = l->head;
    l->head = new_node;
    return;
  }

  while (curr != NULL && count < index - 1){
    curr = curr->next;
    count += 1;
  }

  if (curr == NULL){
    free(new_node);
    return;
  }
  
  node_t *temp = curr->next;
  curr->next = new_node;
  new_node->next = temp;
}

elem list_remove_from_back(list_t *l) { 
  if (l == NULL || l->head == NULL){
    return -1;
  }

  node_t *curr = l->head;

  if (curr->next == NULL){
    elem value = curr->value;
    l->head = NULL;
    free(curr);
    return value;
  }

  while (curr->next->next != NULL){
    curr = curr->next;
  }

  elem value = curr->next->value;
  free(curr->next);
  curr->next = NULL;
  return value;
}

elem list_remove_from_front(list_t *l) { 
  if (l == NULL || l->head == NULL){
    return -1;
  }

  node_t *old_head = l->head;
  elem value = old_head->value;
  l->head = old_head->next;
  old_head->next = NULL;
  
  free(old_head);

  return value;

 }

elem list_remove_at_index(list_t *l, int index) { 
  if (l == NULL || l->head == NULL || index < 1){
    return -1;
  }

  node_t *curr = l->head;

  if (index == 1){
    elem value = curr->value;
    l->head = curr->next;
    free(curr);
    return value;
  }

  int i = 1;
  while (curr != NULL && i < index - 1){
    curr = curr->next;
    i += 1;
  }

  if (curr == NULL || curr->next == NULL){
    return -1;
  }

  node_t *node_removed = curr->next;
  elem value = node_removed->value;
  curr->next = node_removed->next;
  node_removed->next = NULL;
  free(node_removed);
  return value;

 }

bool list_is_in(list_t *l, elem value) { 
  if (l == NULL || l->head == NULL){
    return false;
  }

  node_t *curr = l->head;
  while (curr != NULL){
    if (curr->value == value){
      return true;
    }
    curr = curr->next;
  }

  return false;
 }

elem list_get_elem_at(list_t *l, int index) { 
  if (l == NULL || l->head == NULL || index < 1){
    return -1;
  }

  node_t *curr = l->head;
  int i = 1;

  while(i < index && curr != NULL){
    curr = curr->next;
    i += 1;
  }

  if (curr == NULL){
    return -1;
  }

  return curr->value;
 }

int list_get_index_of(list_t *l, elem value) { 
  if (l == NULL || l->head == NULL){
    return -1;
  }

  node_t *curr = l->head;
  int index = 1;

  while (curr != NULL){
    if(curr->value == value){
      return index;
    }
    index += 1;
    curr = curr->next;
  }

  return -1;
 }

