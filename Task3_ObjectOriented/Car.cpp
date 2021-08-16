#include "Car.h"

Car::Car(){}
Car::Car(int id, std::string name, int posX, int posY) {
	this->_id = id;
	this->_name = name;
	this->_posX = posX;
	this->_posY = posY;
}