#include <iostream>
#include "BaseObject.h"
#include "StaticObject.h"]
#include "DynamicObject.h"
#include "Tree.h"
#include "House.h"
#include "Motorbike.h"
#include "Car.h"
#include <crtdbg.h>
#include <list>

int main() {
	int count = 0;
	//INITIALIZE LIST BaseObject
	std::list<BaseObject*> lbo;

	//INITIALIZE OBJECTS 
	BaseObject* tree = new Tree(1, "Tree", 0, 0);
	BaseObject* house = new House(2, "House", 1, 1);
	BaseObject* motorbike = new Motorbike(3, "Motorbike", 2, 2);
	BaseObject* car = new Car(4, "Car", 3, 3);

	//PUSH OBJECTS INTO LIST
	lbo.push_back(tree);
	lbo.push_back(house);
	lbo.push_back(motorbike);
	lbo.push_back(car);

	//GET IDS AND NAMES OF THE OBJECTS
	std::cout << "**ID AND NAME OF OBJECTS: \n";
	for (auto i : lbo) {
		std::string name = i->getName();
		int id = i->getID();
		std::cout << id << ": " << name << std::endl;
	}

	//GET POSITIONS OF THE OBJECTS
	std::cout << "\n\n**POSITION OF OBJECTS: \n";
	for (auto i : lbo) {
		i->printPosition();
	}

	//MOVE OBJECTS' POSITION X,Y EACH BY 1
	std::cout << "\n\n**START MOVING OBJECTS \n\n";
	std::cout << "Moving...\n\n";
	int x, y;
	for (auto i : lbo) {
		x = i->getPosX();
		y = i->getPosY();
		i->move(x, y);
	}

	//FREE MEMORY AFTER FUNCTIONING
	std::cout << "\n\n";
	/*std::list<BaseObject*>::iterator it;
	for (it = lbo.begin(); it != lbo.end(); it++) {
		lbo.pop_front();
	}*/
	lbo.clear();
	delete tree;
	delete house;
	delete motorbike;
	delete car;

	//_CrtDumpMemoryLeaks();
	return 0;
}