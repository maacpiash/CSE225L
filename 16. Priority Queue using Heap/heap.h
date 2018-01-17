#ifndef HEAP_H
#define HEAP_H

template<class ItemType>
class HeapType
{
public:
    void ReheapDown(int, int);
    void ReheapUp(int, int);
    ItemType *elements;
    int numElements;
};

#endif // HEAP_H

#include "heap.cpp"
