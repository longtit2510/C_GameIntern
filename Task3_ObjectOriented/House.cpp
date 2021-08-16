#include "House.h"

House::House(){}
House::House(int id, std::string name, int posX, int posY) {
	this->_id = id;
	this->_name = name;
	this->_posX = posX;
	this->_posY = posY;
}
House::~House(){}