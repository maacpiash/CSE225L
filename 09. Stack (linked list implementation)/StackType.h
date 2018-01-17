#ifndef STACKTYPE_H
#define STACKTYPE_H

#include <iostream>
using namespace std;

const int MAX_ITEMS = 5;

template <class T>
struct NodeType
{
    T info;
    NodeType* next;
};

class FullStack
{

};

class EmptyStack
{

};

template <class T>
class StackType
{
public:
    StackType();
    ~StackType();
    bool IsFull() const;
    bool IsEmpty() const;
    void Push(T);
    void Pop();
    T Top();
    void PrintList();
private:
    NodeType<T>* topPtr;
};

#include "StackType.cpp"

#endif // STACKTYPE_H
