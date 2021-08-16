#pragma once
#include <string>
class BaseObject
{
public:
	BaseObject();
	BaseObject(int _id, std::string _name, int _posX, int _posY);
	~BaseObject();
	int getID();
	std::string getName();
	int getPosX();
	int getPosY();
	virtual void move(int& posX, int& posY);
	void printPosition();
protected:
	int _id;
	std::string _name;
	int _posX;
	int _posY;
};

