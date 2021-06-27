#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "stackNode.h"
#include "stackItr.h"
using namespace std;

class stackItr; 

class stack {

 public:
  stack();
  ~stack(); // destructor
  bool empty() const;
  void makeEmpty();
  void push(int e);
  void pop();
  int top();
  int size();
  stackItr last(); 

 private:
  stackNode* head;
  stackNode* tail;
  int count; 
};

#endif
