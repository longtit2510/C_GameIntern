#pragma once
#include "StaticObject.h"
class House :
    public StaticObject
{
public:
    House();
    House(int id, std::string name, int posX, int posY);
    ~House();
};

