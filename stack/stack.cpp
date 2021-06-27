#include <iostream>
#include "stack.h"
using namespace std;

stack::stack() {
  head = new stackNode();
  tail = new stackNode();

  head->next = tail;
  tail->previous = head;
  count = 0; 
}

stack::~stack() {
  makeEmpty();
  delete head;
  delete tail; 
}

bool stack::empty() const {
  if (count == 0) {
    return true; 
  }
  return false; 
}

void stack::makeEmpty() {
  while (head->next != tail) {
    pop();
    head->next = head->next; 
  }
  count = 0; 
}

void stack::push(int e) {
  stackNode *pushVal = new stackNode();
  pushVal->value = e;
  pushVal->previous = tail->previous;
  pushVal->next = tail;

  tail->previous = pushVal;

  count += 1;
}

void stack::pop() {
  stackItr iter = last();

  iter.current->previous->next = iter.current->next;
  iter.current->next->previous = iter.current->previous; 

  delete iter.current;
  count -= 1; 
}

int stack::top() {
  return tail->previous->value; 
}

int stack::size() {
  return count; 
}

stackItr stack::last() {
  stackItr last = tail->previous;
  return last; 
} 
