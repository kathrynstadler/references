#include <iostream>
#include "stackItr.h"
using namespace std;

stackItr::stackItr() {
  current = NULL; 
}

stackItr::stackItr(stackNode* theNode) {
  current = theNode; 
} 
