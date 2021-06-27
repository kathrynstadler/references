#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "huffmanNode.h"
using namespace std;

void HuffmanTree(huffmanNode* node, char c, string prefix) {
  if (prefix == "") {
    node->character = c;
    return;
  }
  char first = prefix[0];
  if (first == '0') {
    if (node->left == NULL) {
      node->left = new huffmanNode(); 
    }
    HuffmanTree(node->left, c, prefix.substr(1, prefix.length()-1));
  }
  else {
    if (node->right == NULL) {
      node->right = new huffmanNode(); 
    }
    HuffmanTree(node->right, c, prefix.substr(1, prefix.length()-1)); 
  } 
}

int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    huffmanNode* node = new huffmanNode();
    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
	
	      HuffmanTree(node, character[0], prefix); 
    }

    // read in the second section of the file: the encoded message
    huffmanNode* iter = node; 
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }

	for (int i=0; i <= bits.length(); i++) {
	  if (iter->left == NULL && iter->right == NULL) {
	    cout << iter->character;
	    iter = node; 
	  }
	  else { 
	    if (bits[i] == '0') {
	      iter = iter->left; 
	    }
	    if (bits[i] == '1') {
	      iter = iter->right; 
	    }
	  }
	}
  
        // add it to the stringstream
        sstm << bits;
    }
    cout << endl; 
    string allbits = sstm.str();

    file.close();
}
