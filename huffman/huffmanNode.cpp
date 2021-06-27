#include <iostream>
#include "huffmanNode.h"
using namespace std;

huffmanNode::huffmanNode() {
  character = ' ';
  frequency = 0;
  left = NULL;
  right = NULL;
}

huffmanNode::huffmanNode(char c, int f) {
  character = c;
  frequency = f;
  left = NULL;
  right = NULL;
}

