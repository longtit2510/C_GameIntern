#include "DynamicObject.h"
#include <iostream>

void DynamicObject::move(int& posX, int& posY) {
	posX++;
	posY++;
	std::cout << "After having moved, the position of " << this->getName() <<" is "<< posX << " " << posY << std::endl;
}
DynamicObject::DynamicObject() {

}
