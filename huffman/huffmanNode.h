#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <iostream>
using namespace std;

class huffmanNode {
public:
  huffmanNode();
  huffmanNode(char c, int f);

  huffmanNode* left;
  huffmanNode* right;
  char character;
  int frequency;
};

#endif 
