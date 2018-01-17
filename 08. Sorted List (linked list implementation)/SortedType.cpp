#ifndef SORTEDTYPE_CPP
#define SORTEDTYPE_CPP

#include "SortedType.h"

SortedType :: SortedType()
{
    length = 0;
    listData = NULL;
}

SortedType :: ~SortedType()
{
    MakeEmpty();
}

int SortedType :: GetLength() const
{
    return length;
}

ItemType SortedType ::GetItem(ItemType item, bool &found)
{
    bool moreToSearch;
    NodeType* location;
    location = listData;
    found = false;
    moreToSearch = (location !=NULL);

    while(moreToSearch && !found)
    {
        switch(item.ComparedTo(location->info))
        {
            case LESS:
            case GREATER:
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

void SortedType :: DeleteItem(ItemType item)
{

    bool found = true;
    GetItem(item,found);
    if(!found)
    {
        cout<<"Item is not in the list"<<endl;
        return;
    }

    NodeType* location = listData;
    NodeType* tempLocation;

    if(item.ComparedTo(location->info) == EQUAL)
    {
        tempLocation = location;
        listData = listData->next;
    }

    else
    {
        while(item.ComparedTo(location->next->info)!=EQUAL)
             location = location->next;

         tempLocation = location->next;
         location->next = location->next->next;
    }
    delete tempLocation;
    length--;
}

void SortedType :: MakeEmpty()
{
    NodeType* tempPtr;

    while(listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}

ItemType SortedType :: GetNextItem()
{
    if(currentPos == NULL)
       currentPos = listData;
    else
       currentPos = currentPos->next;
    return currentPos->info;
}

void SortedType :: PutItem (ItemType item)
{
    NodeType* newNode;
    NodeType* predLoc;
    NodeType* location;
    bool moreToSearch;
    location = listData;
    predLoc = NULL;

    moreToSearch = (location != NULL);

    while(moreToSearch)
    {
        if((location->info.ComparedTo(item))==LESS)
        {
            predLoc = location;
            location = location->next;
            moreToSearch = (location!=NULL);
        }
        else
        moreToSearch = false;
    }

    newNode = new NodeType;
    newNode->info = item;

    if(predLoc == NULL)
    {
        newNode->next = listData;
        listData = newNode;
    }
    else
    {
        newNode->next = location;
        predLoc->next = newNode;
    }
    length++;

}

void SortedType :: PrintList()
{
    //This function will print the list
}

void SortedType :: ResetList()
{
    currentPos = NULL;
}

bool SortedType :: IsFull() const
{
    NodeType* location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(bad_alloc &exception)
    {
        return true;
    }
}

#endif //UNSORTEDTYPE_CPP

