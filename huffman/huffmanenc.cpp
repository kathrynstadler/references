#include <iostream>
#include <fstream>
#include <cstdlib>
#include "heap.h"
#include <map>

using namespace std;

void HuffmanTree(heap* h) {
  while(h->size() > 1){
    huffmanNode* newNode = new huffmanNode();
    huffmanNode* n1 = h->findMin(); 
    h->deleteMin();
    huffmanNode* n2 = h->findMin();
    h->deleteMin();
    int f1 = n1->frequency;
    int f2 = n2->frequency; 
    newNode->frequency = f1 + f2; 
    newNode->left = n1;
    newNode->right = n2;
    h->insert(newNode);
  }
}

void printPre(huffmanNode* node, string pre, map<char,string> &premap) {
  if (node->left == NULL && node->right == NULL) {
    if (node->character == ' ') {
      cout << "space" << " " << pre << endl; 
    }
    else {
      cout << node->character << " " << pre << endl;
    }
    premap.insert(pair<char, string>(node->character, pre)); 
  }
  else {
    printPre(node->left, pre + "0", premap);
    printPre(node->right, pre + "1", premap);
  }
} 

int main(int argc, char** argv) {
  
  if (argc != 2) {
    cout << "Must supply the input file name as the one and only parameter" << endl;
    exit(1);
  }

  ifstream file(argv[1]);
  if (!file.is_open()) {
    cout << "Unable to open '" << argv[1] << "' for reading" << endl;
    exit(2);
  }

  char g;
  int total = 0;
  map<char, int> ch_freq; 

  while (file.get(g)) {
    if (ch_freq.find(g) != ch_freq.end()) {
      map<char, int>::iterator it = ch_freq.find(g);
      it->second++; 
      total += 1; 
    }
    else {
      if ((g >= 0x20) && (g <= 0x7e)) {
	ch_freq.insert(pair<char,int>(g,1)); 
	total += 1;
      }
    }
  }

  heap* newHeap = new heap();
  map<char, int>::iterator i;
  for (i=ch_freq.begin(); i != ch_freq.end(); i++) {
    huffmanNode* newNode = new huffmanNode(i->first, i->second);
    newHeap->insert(newNode);
  } 

  map<char, string> ch_str; 
  HuffmanTree(newHeap);
  printPre(newHeap->binheap[1], "", ch_str); 
  
  cout << "----------------------------------------" << endl;

  file.clear(); 
  file.seekg(0);

  map<char,string>::iterator iter;
  string coded = "";
  while(file.get(g)) {
    iter = ch_str.find(g);
    if (iter != ch_str.end()) {
      cout << iter->second << " ";
      coded += iter->second; 
    } 
  }

  cout << endl; 
  file.close();

  cout << "----------------------------------------" << endl;

  int distinct = ch_freq.size();
  int origBits = total*8; 
  double codedLen = coded.length();
  double compressionRatio = total*8/codedLen;
  double huffmanCost = codedLen/total; 

  cout << "There are a total of " << total << " symbols that are encoded." << endl;
  cout << "There are " << distinct << " distinct symbols used." << endl;
  cout << "There were " << origBits << " bits in the original file." << endl;
  cout << "There were " << codedLen << " bits in the compressed file." << endl;
  cout << "This gives a compression ratio of " << compressionRatio << "." << endl;
  cout << "The cost of the Huffman tree is " << huffmanCost << " bits per character." << endl;

  return 0;
  
}
