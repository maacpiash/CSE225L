#ifndef UNSORTEDTYPE_CPP
#define UNSORTEDTYPE_CPP

#include "UnsortedType.h"

UnsortedType::UnsortedType()
{
    length = 0;
    listData = NULL;
}

UnsortedType::~UnsortedType()
{
    //MakeEmpty();
}

int UnsortedType::GetLength() const
{
    return length;
}

ItemType UnsortedType::GetItem(ItemType item, bool& found)
{
    bool moreToSearch;
    NodeType* location;
    location = listData;
    found = false;
    moreToSearch = (location != NULL);

    while(moreToSearch && !found) {
        switch(item.ComparedTo(location->info)) {
        case LESS:
        case GREATER:
            found = false;
            location = location->next;
            moreToSearch = (location != NULL);
            break;
        case EQUAL:
            found = true;
            item = location->info;
            break;
        }
    }
    return item;
}

void UnsortedType::DeleteItem(ItemType item)
{
    NodeType* location = listData;
    NodeType* tempLocation;

    if(item.ComparedTo(location->info) == EQUAL) {
        tempLocation = location;
        listData = listData->next;
    } else {
        while(item.ComparedTo(location->next->info) != EQUAL)
            location = location->next;
        tempLocation = location->next;
        location->next = location->next->next;
    }

    delete tempLocation;
    length--;
}

void UnsortedType::MakeEmpty()
{
    NodeType* tempPtr;

    while(listData != NULL) {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }

    length = 0;
}

ItemType UnsortedType::GetNextItem()
{
    if(currentPos == NULL)
        currentPos = listData;
    else
        currentPos = currentPos->next;
    return currentPos->info;
}

void UnsortedType::PutItem(ItemType item)
{
    NodeType* location;
    location = new NodeType;
    location->info = item;
    location->next = listData;
    listData = location;
    length++;
}

void UnsortedType::PrintList()
{
    NodeType* location = listData;
    while(location != NULL) {
        location->info.Print();
        location = location->next;
    }
    cout << endl;
}

void UnsortedType::ResetList()
{
    currentPos = NULL;
}

bool UnsortedType::IsFull() const
{
    NodeType* location;
    try {
        location = new NodeType;
        delete location;
        return false;
    } catch (bad_alloc &exception) {
        return true;
    }
}

#endif // UNSORTEDTYPE_CPP
