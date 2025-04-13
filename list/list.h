#ifndef _LIST_H_
#define _LIST_H_

typedef struct cell{
  int val;
  struct cell *prev, *next;
}cell;

typedef cell *list; 

list emptyList();

int firstValue(list l);

list insertFirst(list l, int val);

list insertLast(list l, int val);

list removeValue(list l, int val);

list removeFirst(list l);

void printList(list l);

void freeList(list l);

#endif
