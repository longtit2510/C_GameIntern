#include <iostream>
#include "Door.h"

int main() {
	//INIT A DOOR
	Door* door = new Door();
	
	std::cout << "***DOOR CONTROL APPLICATION***\n\n";

	//INIT SOME VARIABLES FOR THE LOOP
	int exit = 0;
	std::string action = "";

	//THE DEFAULT STATUS OF DOOR IS SET TO "CLOSED" - IMPLEMENTED IN DOOR.CPP
	std::cout << "THE DOOR'S DEFAULT STATUS IS CLOSED";
	
	//DISPLAY DOOR CONTROL TO CONSOLE
	std::cout << "\nCHOOSE ACTION BY ENTER ONE OF THE FOLLOWING NUMBERS:\n"
		<< "1: OPEN THE DOOR\n"
		<< "2: CLOSE THE DOOR\n"
		<< "3: LOCK THE DOOR\n"
		<< "4: UNLOCK THE DOOR\n"
		<< "5: SHOW DOOR'S CURRENT STATUS\n"
		<< "6: QUIT APP\n";

	//ACTION LOOP
	while (exit != 10) {
		std::cout << "\n__ENTER YOUR NUMBER: ";
		std::cin >> action;
		if (action == "1") {
			door->open();
		}
		else if (action == "2") {
			door->close();
		}
		else if (action == "3") {
			door->lock();
		}
		else if (action == "4") {
			door->unlock();
		}
		else if (action == "5") {
			door->displayCurrentState();
		}
		else if (action == "6") {
			exit = 10;
		}
		else {
			std::cout << "\nYOU MUST ENTER A VALID NUMBER\n";
		}
	}

	return 0;
}