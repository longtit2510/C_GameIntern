#pragma once
#include "StaticObject.h"
class Tree :
    public StaticObject
{
public:
    Tree();
    Tree(int id, std::string name, int posX, int posY);
    ~Tree();
};

