#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>
using namespace std;

enum RelationType {LESS,GREATER,EQUAL};

class ItemType
{
    public:

    ItemType();
    RelationType ComparedTo(ItemType) const;
    void Print() const;
    void Initialize(int number);

    private:
    int value;

};

#endif //ITEMTYPE_H
