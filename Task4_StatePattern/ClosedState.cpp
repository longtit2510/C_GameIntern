#include "ClosedState.h"
#include "OpennedState.h"
#include "LockedState.h"
#include <iostream>

void ClosedState::displayState() {
	std::cout << "\n**DOOR STATUS: CLOSED\n";
}
void ClosedState::open(Door* door) {
	std::cout << "\nYOU ARE OPENING THE DOOR...\n";
	door->setState(new OpennedState);
	std::cout << "....\n";
	std::cout << "THE DOOR IS OPENED\n";
}
void ClosedState::close(Door* door) {
	std::cout << "\nTHE DOOR IS CLOSED THEREFORE YOU CANNOT CLOSE IT, PLEASE OPEN IT FIRST\n";
}
void ClosedState::lock(Door* door) {
	std::cout << "\nYOU ARE LOCKING THE DOOR...\n";
	door->setState(new LockedState);
	std::cout << "....\n";
	std::cout << "THE DOOR IS LOCKED\n";
}
void ClosedState::unlock(Door* door) {
	std::cout << "\nTHE DOOR IS NOT LOCKED THEREFORE YOU CANNOT UNLOCK IT, PLEASE LOCK IT FIRST\n";
}