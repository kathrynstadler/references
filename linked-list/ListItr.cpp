#include <iostream>
#include "ListItr.h"
using namespace std;

// constructors 
ListItr::ListItr() {
  current = NULL; 
}

ListItr::ListItr(ListNode* theNode) {
  current = theNode; 
}

bool ListItr::isPastEnd() const {
  if(current->next == NULL) {
    return true; 
  }
  return false; 
}

bool ListItr::isPastBeginning() const {
  if (current->previous == NULL) {
    return true; 
  }
  return false; 
}

void ListItr::moveForward() {
  if (isPastEnd() != true) {
    current = current->next;
  } 
}

void ListItr::moveBackward() {
  if (isPastBeginning() != true) {
    current = current->previous;
  } 
}

int ListItr::retrieve() const {
  int retVal = current->value; 
  return retVal; 
} 
