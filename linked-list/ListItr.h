/*
 * Filename: ListItr.h
 * Description: ListItr class definition
 */
#ifndef LISTITR_H
#define LISTITR_H

#include "ListNode.h"
#include "List.h"

class ListItr {
public:
    // Constructors
    ListItr();
    ListItr(ListNode* theNode);

    // returns true if the iterator is currently pointing past the end position
    bool isPastEnd() const;

    // returns true if the iterator is currently pointing past (before) the first position
    bool isPastBeginning() const;

    void moveForward();
    void moveBackward();

    // returns the value of the item in the current position of the list
    int retrieve() const;

private:
    ListNode* current; // holds the position in the list

    friend class List; // list class needs access to "current"
};

#endif
