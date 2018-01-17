#ifndef QUEUETYPE_H
#define QUEUETYPE_H

template<class ItemType>
class Queue
{
public:
	Queue();
	Queue(int);
	~Queue();
	bool isEmpty() const;
	bool isFull() const;
	void makeEmpty();
	void Enqueue(ItemType);
	void Dequeue();
	void printQueue();
private:
	int head;
	int tail;
	int maxSize;
	ItemType *items;
};

#endif

#include "Queue.cpp"