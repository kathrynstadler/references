/*
 * Filename: List.h
 * Description: List class definition
 */
 
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNode.h"
#include "ListItr.h"
using namespace std;

class ListItr;

class List {
public:
    // default constructor
    List();

    // copy constructor
    List(const List& source);

    // destructor
    ~List();

    // copy assignment operator
    List& operator=(const List& source);

    // returns true if empty, else false
    bool isEmpty() const;

    // removes (deletes) all items except the dummy head/tail.
    void makeEmpty();

    ListItr first();
    ListItr last();

    // inserts x after current iterator position
    void insertAfter(int x, ListItr position);

    // inserts x before current iterator position
    void insertBefore(int x, ListItr position);

    // inserts x at tail of list
    void insertAtTail(int x);

    ListItr find(int x);

    // removes the first occurrence of x
    void remove(int x);

    // returns the number of elements in the list
    int size() const;

private:
    ListNode* head;       // Dummy node representing the beginning of the list
    ListNode* tail;       // Dummy node representing the end of the list
    int count;            // Number of elements in the list
};

// printList: non-member function prototype
// prints list forwards (head -> tail) when forward is true
// prints list backwards (tail -> head) when forward is false
void printList(List& source, bool forward);

#endif
