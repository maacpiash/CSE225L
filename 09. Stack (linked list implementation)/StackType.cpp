#ifndef STACKTYPE_CPP
#define STACKTYPE_CPP

#include "StackType.h"

template <class T>
StackType<T>::StackType()
{
    topPtr = NULL;
}

template <class T>
StackType<T>::~StackType()
{
    NodeType<T>* tempPtr;
    while(topPtr != NULL){
        tempPtr = topPtr;
        topPtr = tempPtr->next;
        delete tempPtr;
    }
}

template <class T>
void StackType<T>::Push(T newItem)
{
    if(IsFull())
        throw FullStack();
    else {
        NodeType<T>* location;
        location = new NodeType<T>;
        location->info = newItem;
        location->next = topPtr;
        topPtr = location;
    }
}

template <class T>
void StackType<T>::Pop()
{
    if(IsEmpty())
        throw EmptyStack();
    else {
        NodeType<T>* tempPtr;
        tempPtr = topPtr;
        topPtr = tempPtr->next;
        delete tempPtr;
    }
}

template <class T>
T StackType<T>::Top()
{
    if(IsEmpty())
        throw EmptyStack();
    else
        return topPtr->info;
}

template <class T>
bool StackType<T>::IsEmpty() const
{
    return (topPtr == NULL);
}

template <class T>
bool StackType<T>::IsFull() const
{
    NodeType<T>* location;

    try {
        location = new NodeType<T>;
        delete location;
        return false;
    } catch(std::bad_alloc exception) {
        return true;
    }
}

#endif // STACKTYPE_CPP
