#ifndef QUEUETYPE_CPP
#define QUEUETYPE_CPP

#include "Queue.h"
#include <iostream>
using namespace std;

template<class ItemType>
Queue<ItemType>::Queue()
{
	maxSize = 5;
	head = -1;
	tail = -1;
	items = new ItemType[maxSize];
}

template<class ItemType>
Queue<ItemType>::Queue(int max)
{
	maxSize = max;
	head = -1;
	tail = -1;
	items = new ItemType[maxSize];
}

template<class ItemType>
Queue<ItemType>::~Queue()
{
	delete items[];
}

template<class ItemType>
bool Queue<ItemType>::isFull() const
{
	return (tail == maxSize - 1);
}

template<class ItemType>
void Queue<ItemType>::makeEmpty()
{
	while(!isEmpty())
		Dequeue();
}

template<class ItemType>
void Queue<ItemType>::Enqueue(ItemType item)
{
	if(isFull()) {
		cout << "Queue Overflow!" << endl;
		return;
	}
	items[++tail] = item;
}

template<class ItemType>
void Queue<ItemType>::Dequeue()
{
	if(isEmpty()) {
		cout << "Queue Underflow!" << endl;
		return;
	}
	cout << "Deleted " << items[++head] << endl;
}


template<class ItemType>
void Queue<ItemType>::printQueue()
{
    if(isEmpty()) {
	cout << "ERROR, queue is empty!" << endl;
	return;
    }
    for(int i = head; i % maxSize != tail; i++)
         cout << items[i % maxSize] << " ";
}
		