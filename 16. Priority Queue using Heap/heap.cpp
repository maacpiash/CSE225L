#ifndef HEAP_CPP
#define HEAP_CPP
#include "heap.h"

#include <algorithm>
using namespace std;

template<class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom)
{
    int maxChild, rightChild, leftChild;
    leftChild = 2 * root + 1;
    rightChild = 2 * root + 2;
    if(leftChild <= bottom) {
        if(leftChild == bottom)
            maxChild = leftChild;
    } else {
        if(elements[leftChild] <= elements[rightChild])
            maxChild = rightChild;
        else
            maxChild = leftChild;
    }
    if(elements[root] < elements[maxChild]) {
        swap(elements[root], elements[maxChild]);
        ReheapDown(maxChild, bottom);
    }
}

template<class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom)
{
    int parent;
    if(bottom > root) {
        parent = (bottom - 1) / 2;
        if(elements[parent] < elements[bottom]) {
            swap(elements[parent], elements[bottom]);
            ReheapUp(root, parent);
        }
    }
}

#endif // HEAP_CPP
