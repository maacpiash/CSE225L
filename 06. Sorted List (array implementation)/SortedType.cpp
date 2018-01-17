
#ifndef SORTEDTYPE_CPP
#define SORTEDTYPE_CPP

#include "SortedType.h"

SortedType::SortedType()
{
    length = 0;
}

bool SortedType::IsFull() const
{
    return (length == MAX_ITEMS);
}

int SortedType::GetLength() const
{
    return length;
}

ItemType SortedType::GetItem(ItemType item, bool& found)
{
    int midPoint;
    int first = 0;
    int last = length - 1;
    bool moreToSearch = (first <= last);
    found = false;

    while (moreToSearch && !found) {
        midPoint = (first + last) / 2;
        switch(item.ComparedTo(info[midPoint])) {
        case LESS:
            last = midPoint - 1;
            moreToSearch = (first <= last);
            break;
        case GREATER:
            first = midPoint + 1;
            moreToSearch = (first <= last);
            break;
        case EQUAL:
            found = true;
            item = info[midPoint];
            break;
        }
    }

    return item;
}

void SortedType::PutItem(ItemType item)
{
    bool moreToSearch;
    int location = 0;
    moreToSearch = (location < length);

    while(moreToSearch) {
        switch(item.ComparedTo(info[location])) {
        case LESS:
            moreToSearch = false;
            break;
        case GREATER:
            location++;
            moreToSearch = (location < length);
            break;
        }
    }

    for(int index = length; index > location; index--)
        info[index] = info[index - 1];
    info[location] = item;
    length++;
}

void SortedType::DeleteItem(ItemType item)
{
    bool moreToSearch;
    int location = 0;
    moreToSearch = (location < length);

    while(moreToSearch) {
        switch(item.ComparedTo(info[location])) {
        case LESS:
            moreToSearch = false;
            cout << "The item is not in the list" << endl;
            break;
        case GREATER:
            location++;
            moreToSearch = (location < length);
            break;
        case EQUAL:
            moreToSearch = false;
            break;
        }
    }

    for(int index = location + 1; index < length; index++)
        info[index - 1] = info[index];
    length--;
}

void SortedType::ResetList()
{
    currentPos = -1;
}

ItemType SortedType::GetNextItem()
{
    currentPos++;
    return info[currentPos];
}

void SortedType::MakeEmpty()
{
    length = 0;
}

void SortedType::PrintList()
{
    ResetList();
    for(int i = 0; i < length; i++)
        GetNextItem().Print();

    cout << endl;
}

#endif // SORTEDTYPE_CPP
