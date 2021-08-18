#pragma once
#include "Door.h"
class Door;

class StateBase
{
public:
	virtual void displayState() =0;
	virtual void open(Door* door) =0;
	virtual void close(Door* door) = 0;
	virtual void lock(Door* door) = 0;
	virtual void unlock(Door* door) = 0;
};

