#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

#include "ItemType.h"
#include <new>

using namespace std;

struct NodeType;

class UnsortedType
{
public:
    UnsortedType();
    ~UnsortedType();
    bool IsFull() const;
    int GetLength() const;
    ItemType GetItem(ItemType item, bool& found);
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

struct NodeType {
    ItemType info;
    NodeType* next;
};

#endif // UNSORTEDTYPE_H
