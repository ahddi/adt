#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "../stack/stack.h"

/* An implementation of queues using two stacks (in and out) */

typedef struct{
  int val;
  stack pIn, pOut;
}structQueue;

typedef structQueue *queue;

queue emptyQueue();

int isEmptyQueue(queue q);

queue enqueue(queue q, int val);

queue dequeue(queue q);

int peek(queue q);

void printQueue(queue q);

void freeQueue(queue q);

#endif
