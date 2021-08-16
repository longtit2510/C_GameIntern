#include "BaseObject.h"
#include <string>
#include <iostream>
BaseObject::BaseObject() {}
BaseObject::BaseObject(int _id, std::string _name, int _posX, int _posY) {
	this->_id = _id;
	this->_name = _name;
	this->_posX = _posX;
	this->_posY = _posY;
}
BaseObject::~BaseObject() {
	std::cout << this->getName() << " deleted!!" << std::endl;
}
void BaseObject::move(int &posX,int &posY){}
void BaseObject::printPosition() {
	std::cout << this->getName() << ": " << this->_posX << " " << this->_posY << std::endl;
}
std::string BaseObject::getName() {
	return this->_name;
}
int BaseObject::getID() {
	return this->_id;
}
int BaseObject::getPosX() {
	return this->_posX;
}
int BaseObject::getPosY() {
	return this->_posY;
}

