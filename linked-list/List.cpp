#include <iostream>
#include "List.h"
using namespace std;

// default constructor 
List::List() {
  int count;

  head = new ListNode();
  tail = new ListNode();
  
  head->next=tail;
  tail->previous=head;
  count = 0; 
}

// copy constructor 
List::List(const List& source) {
  head = new ListNode();
  tail = new ListNode();
  head->next=tail;
  tail->previous=head;
  count=0;

  ListItr iter(source.head->next);
  while(!iter.isPastEnd()) {
    insertAtTail(iter.retrieve());
    iter.moveForward(); 
  } 
}

// destructor 
List::~List() {
  makeEmpty();
  delete head;
  delete tail; 
}

// copy assignment operator
List& List::operator=(const List& source) {
  if (this == &source) {
    return *this; 
  }
  else {
    makeEmpty();
    ListItr iter(source.head->next);
    while(!iter.isPastEnd()) {
      insertAtTail(iter.retrieve());
      iter.moveForward(); 
    } 
  }
  return *this; 
} 

bool List::isEmpty() const {
  if (size() == 0) {
    return true; 
  }
  return false; 
}

void List::makeEmpty() {
  while (head->next != tail) {
    remove(head->next->value);
    head->next = head->next; 
  }
  count = 0; 
}

ListItr List::first() {
  ListItr first = head->next; 
  return first;
}

ListItr List::last() {
  ListItr last = tail->previous; 
  return last;   
}

void List::insertAfter(int x, ListItr position) {
  ListNode *newListNode = new ListNode();

  newListNode->value = x; 
  newListNode->next = position.current->next;
  newListNode->previous = position.current;
  
  position.current->next = newListNode;
  position.current->next->previous = newListNode;

  count += 1; 
}

void List::insertBefore(int x, ListItr position) {
  ListNode *newListNode = new ListNode();

  newListNode->value = x;
  newListNode->next = position.current;
  newListNode->previous = position.current->previous;
  
  position.current->previous->next = newListNode;
  position.current->previous = newListNode;

  count += 1; 
}

void List::insertAtTail(int x) {
  ListNode *newListNode = new ListNode();
  ListItr iter = last();

  newListNode->value = x;
  newListNode->next = tail;
  newListNode->previous = iter.current;

  iter.current->next->previous = newListNode;
  iter.current->next = newListNode;
  

  count += 1;
}

ListItr List::find(int x) {
  ListItr iter  = first();

  while (iter.isPastEnd() == false) {
    if (x == iter.current->value) {
      return iter; 
    } 
    iter.moveForward(); 
  }
  return iter; // element was not found. returns iter that points to dummy tail node
}


void List::remove(int x) {
  ListItr iter = find(x);

  if (iter.current->value == x) { 
    iter.current->previous->next = iter.current->next; 
    iter.current->next->previous = iter.current->previous; 
 
    delete iter.current;
  
    count -= 1;
  }
}

int List::size() const {
  return count;
}

void printList(List& source, bool forward) {
  ListItr iterForward = source.first();
  ListItr iterBackward = source.last(); 

  if (forward) {
    while(iterForward.isPastEnd() != true) {
      cout << iterForward.retrieve() << " ";
      iterForward.moveForward(); 
    }
  }
  else {
    while(iterBackward.isPastBeginning() != true) {
      cout << iterBackward.retrieve() << " ";
      iterBackward.moveBackward(); 
    } 
  } 
} 
