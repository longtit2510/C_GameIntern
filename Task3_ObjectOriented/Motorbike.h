#pragma once
#include "DynamicObject.h"
class Motorbike :
    public DynamicObject
{
public:
    Motorbike();
    Motorbike(int id, std::string name, int posX, int posY);
};

