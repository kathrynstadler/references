#ifndef HEAPNODE_H
#define HEAPNODE_H
#include <iostream>
using namespace std;

class heapNode {
public:
  heapNode();
  heapNode(int f, char c);
  int getFrequency();
  char getCharacter();
  heapNode* getLeft();
  heapNode* getRight();

private:
  heapNode* left;
  heapNode* right;
  int frequency;
  char character;
  friend class heap; 
};

#endif 
