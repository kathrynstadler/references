#include <iostream>
#include "heap.h"
#include "huffmanNode.h"
using namespace std;

// default constructor
heap::heap() : heap_size(0) {
    binheap.push_back(0);
}

// builds a heap from an unsorted vector
heap::heap(vector<huffmanNode*> vec) : heap_size(vec.size()) {
    binheap = vec;
    binheap.push_back(binheap[0]);
    huffmanNode* node = new huffmanNode(); 
    binheap[0] = node;
    for (int i = heap_size/2; i > 0; i--) {
        percolateDown(i);
    }
}

heap::~heap() {
}

void heap::insert(int c, char f) {
  // a vector push_back will resize as necessary
  huffmanNode* node = new huffmanNode(c, f);
  binheap.push_back(node);
  // move it up into the right position
  percolateUp(++heap_size);
}

void heap::insert(huffmanNode* node) {
  binheap.push_back(node);
  percolateUp(++heap_size); 
} 

void heap::percolateUp(int hole) {
  // get the value just inserted
  huffmanNode* node = binheap[hole];
  int x = binheap[hole]->frequency;
  for ( ; (hole > 1) && (x < binheap[hole/2]->frequency); hole /= 2) {
    binheap[hole] = binheap[hole/2]; // move the parent down
  }
  binheap[hole] = node;
}

huffmanNode* heap::deleteMin() {
  // make sure the heap is not empty
  if (heap_size == 0) {
    throw "deleteMin() called on empty heap";
  }
  
  // save the value to be returned
  huffmanNode* ret = binheap[1];
  // move the last inserted position into the root
  binheap[1] = binheap[heap_size--];
  // make sure the vector knows that there is one less element
  binheap.pop_back();
  // percolate the root down to the proper position
  if (!isEmpty()) {
    percolateDown(1);
  }
  // return the old root node
  return ret;
}

void heap::percolateDown(int hole) {
  // get the value to percolate down
  huffmanNode* node = binheap[hole];
  int x = binheap[hole]->frequency;
  while (hole*2 <= heap_size) {
    int child = hole*2; // the left child
    if ((child+1 <= heap_size) && (binheap[child+1]->frequency < binheap[child]->frequency)) {
      child++;
    }
    if (x > binheap[child]->frequency) {
      binheap[hole] = binheap[child]; // move child up
      hole = child;                   // move hole down
    } else {
      break;
    }
  }
  binheap[hole] = node;
}

huffmanNode* heap::findMin() {
    if (heap_size == 0) {
        throw "findMin() called on empty heap";
    }
    return binheap[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
    binheap.resize(1);
}

bool heap::isEmpty() {
    return heap_size == 0;
}
