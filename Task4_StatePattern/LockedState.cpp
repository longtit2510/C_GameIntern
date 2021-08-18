#include "LockedState.h"
#include "ClosedState.h"
#include <iostream>

void LockedState::displayState() {
	std::cout << "\n**DOOR STATUS: LOCKED\n";
}
void LockedState::open(Door* door) {
	std::cout << "THE DOOR IS LOCKED THEREFORE YOU CANNOT OPEN IT, PLEASE UNLOCK IT FIRST\n";
}
void LockedState::close(Door* door) {
	std::cout << "THE DOOR IS LOCKED, YOU MUST UNLOCK IT FIRST\n";
}
void LockedState::lock(Door* door) {
	std::cout << "THE DOOR IS LOCKED THEREFORE YOU CANNOT LOCK IT, PLEASE UNLOCK FIRST THEN LOCK IT AGAIN\n";
}
void LockedState::unlock(Door* door) {
	std::cout << "\nYOU ARE UNLOCKING THE DOOR...\n";
	door->setState(new ClosedState);
	std::cout << "....\n";
	std::cout << "THE DOOR IS UNLOCKED\n";
}
