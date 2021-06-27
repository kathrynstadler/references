#ifndef HEAP_H
#define HEAP_H

#include "huffmanNode.h"
#include <vector>
using namespace std;

class heap {
    public:
        heap();
        heap(vector<huffmanNode*> vec);
        ~heap();

        void insert(int c, char f);
        void insert(huffmanNode* node); 
        huffmanNode* findMin();
        huffmanNode* deleteMin();
        unsigned int size();
        void makeEmpty();
        bool isEmpty();

        vector<huffmanNode*> binheap;
        unsigned int heap_size;
        void percolateUp(int hole);
        void percolateDown(int hole);
};

#endif
