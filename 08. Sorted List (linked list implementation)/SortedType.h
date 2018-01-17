#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H

#include "ItemType.h"
#include <new>
#include <iostream>

using namespace std;
struct NodeType;

class SortedType
{
    public:

    SortedType();
    ~SortedType();

    bool IsFull() const;
    int GetLength() const;
    ItemType GetItem (ItemType item, bool &found);
    void PutItem(ItemType item);
    void DeleteItem(ItemType item);
    void MakeEmpty();
    void ResetList();
    ItemType GetNextItem();
    void PrintList();

    private:

    NodeType* listData;
    int length;
    NodeType* currentPos;
};

struct NodeType
{
    ItemType info;
    NodeType* next;
};

#endif //SORTEDTYPE_H

