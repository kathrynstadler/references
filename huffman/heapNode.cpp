#include <iostream>
#include "huffmanNode.h"
using namespace std;

huffmanNode::huffmanNode() {
  frequency = 0;
  character = ' ';
  left = NULL;
  right = NULL;
}

huffmanNode::huffmanNode(int f, char c) {
  frequency = f;
  character = c;
  left = NULL;
  right = NULL;
}

int huffmanNode::getFrequency() {
  return frequency; 
}

char huffmanNode::getCharacter() {
  return character; 
}

huffmanNode* huffmanNode::getLeft() {
  return left; 
}

huffmanNode* huffmanNode::getRight() {
  return right; 
} 

