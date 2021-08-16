#pragma once
#include "BaseObject.h"
class DynamicObject :
    public BaseObject
{
public:
    DynamicObject();
    void move(int& posX, int& posY) override;
};

