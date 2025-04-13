#include "stack.h"

stack emptyStack(){
  return emptyList();
}

stack push(stack s, int val){
  s = insertFirst(s, val);
  return s;
}

int top(stack s){
  return firstValue(s);
}

stack pop(stack s){
  s = removeFirst(s);
  return s;
}

void printStack(stack s){
  printList(s);
  return;
}

void freeStack(stack s){
  freeList(s);
  return;
}
