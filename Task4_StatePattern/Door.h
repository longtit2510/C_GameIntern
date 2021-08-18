#pragma once
#include "StateBase.h"

class StateBase;

class Door
{
private:
	StateBase* m_state;
public:
	Door();
	void setState(StateBase* newState);
	void displayCurrentState();
	void open();
	void close();
	void lock();
	void unlock();
};

