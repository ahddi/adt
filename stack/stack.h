#ifndef _STACK_H_
#define _STACK_H_

#include "../list/list.h"
#define EMPTY_QUEUE -999999

/* An implementation of stacks using double-linked circular lists */

typedef list stack;

stack emptyStack();

stack push(stack s, int val);

int top(stack s);

stack pop(stack s);

void printStack(stack s);

void freeStack(stack s);

#endif
