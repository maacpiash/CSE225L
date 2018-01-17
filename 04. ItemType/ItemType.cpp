#ifndef ITEMTYPE_CPP
#define ITEMTYPE_CPP

#include "ItemType.h"

ItemType::ItemType()
{
    value = 0;
}

RelationType ItemType :: ComparedTo(ItemType otherItem) const
{
    if (value<otherItem.value)
      return LESS;

    else if(value>otherItem.value)
      return GREATER;

    else
      return EQUAL;

}

void ItemType :: Initialize(int number)
{
    value = number;
}

void ItemType :: Print() const
{
    cout<< value << " ";
}

#endif //ITEMTYPE_CPP
