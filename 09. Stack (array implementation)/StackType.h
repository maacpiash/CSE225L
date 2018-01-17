#ifndef STACKTYPE_H
#define STACKTYPE_H

#define MAX 5

#include <iostream>
using namespace std;

template<class T>
class StackType
{
    public:

    StackType();
    bool IsEmpty() const;
    bool IsFull() const;
    void Push(T item);
    void Pop();
    T Top() const;

    private:

    int tos;
    T items[MAX];
};

#endif //STACKTYPE_H
#include "StackType.cpp"
