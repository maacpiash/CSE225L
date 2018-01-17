#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "heap.h"

template<class ItemType>
class PQType
{
public:
    PQType(int);
    ~PQType();
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(ItemType);
    void Dequeue(ItemType&);
private:
    int numItems;
    HeapType<ItemType> heap;
    int maxItems;
};

#endif // PRIORITYQUEUE_H

#include "priorityQueue.cpp"
