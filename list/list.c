#include "list.h"
#include <stdlib.h>
#include <stdio.h>

#define IS_EMPTY -999999

list emptyList(){
  return NULL;
}

int isEmpty(list l){
  return (l == NULL);
}

int firstValue(list l){
  if (isEmpty(l)){
    return IS_EMPTY;
  }
  return l->val;
}

list insertFirst(list l, int val){
  list lNew = NULL;

  lNew = (list) malloc(sizeof(cell));
  if (isEmpty(lNew)){
    fprintf(stderr, "Allocation error\n");
    exit(EXIT_FAILURE);
  }

  lNew->val = val;
  if (isEmpty(l)){
    lNew->next = lNew;
    lNew->prev = lNew;
    return lNew;
  }else{
    lNew->prev = l->prev;
    lNew->next = l;
    l->prev->next = lNew;
    l->prev = lNew;
    return lNew;
  }
}

list insertLast(list l, int val){
  l = insertFirst(l, val);
  return l->next;
}

list removeValue(list l, int val){
  list curr = l;
  int rem;

  /* Empty list case */
  if (isEmpty(l)){
    return l;
  }

  /* Single-element list case */
  if (curr->next == curr){
    if (curr->val == val){
      return emptyList();
    }else{
      return l;
    }
  }

  /* General case */
  do{
    curr = curr->next;
  }while (curr != l && curr->val != val);

  if (curr->val == val){
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    free(curr);
  }

  return l;
}

list removeFirst(list l){
  list lnew = l->next;

  if (isEmpty(l)){
    return l;
  }
  if (lnew == l){
    return emptyList();
  }

  l->prev->next = l->next;
  l->next->prev = l->prev;
  free(l);
  return lnew;
}

void printList(list l){
  list curr = l;

  if (isEmpty(l)){
    return ;
  }

  printf("[ ");
  do{
    printf("%d ", curr->val);
    curr = curr->next;
  }while (curr != l);
  printf("]\n");

  return;
}

void freeList(list l){
  list curr = l, next;

  if (isEmpty(l)){
    return ;
  }

  do{
    next = curr->next;
    free(curr);
    curr = next;
  }while (curr != l);

  return;
}
