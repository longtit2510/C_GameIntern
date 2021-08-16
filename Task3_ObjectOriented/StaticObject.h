#pragma once
#include "BaseObject.h"
class StaticObject :
    public BaseObject
{
public:
    StaticObject();
    void move(int& posX, int& posY) override;
};

