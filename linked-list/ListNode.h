/*
 * Filename: ListNode.h
 * Description: ListNode class definition
 */

#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

// next line needed because NULL is part of std namespace
using namespace std;

class ListNode {
public:
    ListNode();         // Constructor

private:
    int value;          // value of the node
    ListNode* next;     // next ListNode in the List
    ListNode* previous; // previous ListNode in the list

    // List needs access to value, next, and previous
    friend class List;

    // ListItr needs access to value
    friend class ListItr;
};

#endif
