#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H

#include "ItemType.h"
const int MAX_ITEMS = 5;

class SortedType
{
public:
    SortedType();
    bool IsFull() const;
    void MakeEmpty();
    int GetLength() const;
    ItemType GetItem(ItemType item, bool& found);
    void PutItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetList();
    ItemType GetNextItem();
    void PrintList();
private:
    int length;
    ItemType info[MAX_ITEMS];
    int currentPos;
};
#endif // SORTEDTYPE_H
