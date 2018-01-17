#ifndef QUEUETYPE_LL_H
#define QUEUETYPE_LL_H

#include <iostream>
#include <new>
using namespace std;

class FullQueue { };

class EmptyQueue { };

template <class ItemType>
struct NodeType
{
    ItemType info;
    NodeType* next;
};

template <class ItemType>
class QueueType
{
public:
    QueueType();
    ~QueueType();
    void makeEmpty();
    void enqueue(ItemType);
    void dequeue(ItemType&);
    bool IsEmpty() const;
    bool IsFull() const;
private:
    NodeType <ItemType>* front;
    NodeType <ItemType>* rear;

};

#endif //QUEUETYPE_LL_H
#include "Queue_LL.cpp"
