#ifndef STACKTYPE_CPP
#define STACKTYPE_CPP

#include "StackType.h"

template<class T>
StackType<T> :: StackType()
{
    tos = -1;
    cout<<"Initializing!\n";
}

template <class T>
void StackType<T> :: Push(T item)
{
    items[++tos] = item;
}

template <class T>
void StackType<T> :: Pop()
{
    return items[tos--];
}

template <class T>
T StackType<T> :: Top() const
{
    return items[tos];
}

#endif //STACKTYPE_CPP
