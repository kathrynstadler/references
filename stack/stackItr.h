#ifndef STACKITR_H
#define STACKITR_H

#include "stackNode.h"
#include "stack.h"
using namespace std; 

class stackItr {

 public:
  stackItr();
  stackItr(stackNode* theNode); 

 private:
  stackNode* current;
  friend class stack; 

};

#endif 
