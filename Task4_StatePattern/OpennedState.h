#pragma once
#include "StateBase.h"
class OpennedState :
    public StateBase
{
public: 
	void displayState() override;
	void open(Door* door) override;
	void close(Door* door) override;
	void lock(Door* door) override;
	void unlock(Door* door) override;
};

