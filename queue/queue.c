#include "queue.h"
#include "../stack/stack.h"
#include <stdio.h>
#include <stdlib.h>


queue emptyQueue(){
  queue q;

  q = (queue) malloc(sizeof(structQueue));
  if (q == NULL){
    fprintf(stderr, "Allocation error\n");
    exit(EXIT_FAILURE);
  }
  q->pIn = emptyStack();
  q->pOut = emptyStack();

  return q;
}

int isEmptyQueue(queue q){
  return (isEmpty(q->pIn) && isEmpty(q->pOut));
}

queue enqueue(queue q, int val){
  q->pIn = push(q->pIn, val);
  return q;
}

queue dequeue(queue q){
  if (isEmptyQueue(q)){
    return q;
  }

  if (isEmpty(q->pOut)){
    while (!isEmpty(q->pIn)){
      q->pOut = push(q->pOut, top(q->pIn));
      q->pIn = pop(q->pIn);
    }
  }
  q->pOut = pop(q->pOut);

  return q;
}

int peek(queue q){
  if (isEmptyQueue(q)){
    return EMPTY_QUEUE;
  }

  if (isEmpty(q->pOut)){
    while (!isEmpty(q->pIn)){
      q->pOut = push(q->pOut, top(q->pIn));
      q->pIn = pop(q->pIn);
    }
  }
  return top(q->pOut);
}

void printQueue(queue q){
  printf("pOut : ");
  printStack(q->pOut);
  printf("\npIn : ");
  printStack(q->pIn);
  printf("\n");
  return;
}

void freeQueue(queue q){
  freeStack(q->pIn);
  freeStack(q->pOut);
  free(q);
  return;
}

