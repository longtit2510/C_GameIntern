#include "OpennedState.h"
#include "ClosedState.h"
#include <iostream>

void OpennedState::displayState() {
	std::cout << "\n**DOOR STATUS: OPENNED\n";
}
void OpennedState::open(Door* door) {
	std::cout << "THE DOOR IS OPPENED THEREFORE YOU CANNOT OPEN IT, PLEASE CLOSE IT FIRST\n";
}
void OpennedState::close(Door* door) {
	std::cout << "\nYOU ARE CLOSING THE DOOR...\n";
	door->setState(new ClosedState);
	std::cout << "....\n";
	std::cout << "THE DOOR IS CLOSED\n";
}
void OpennedState::lock(Door* door) {
	std::cout << "THE DOOR IS OPENNED THEREFORE YOU CANNOT LOCK IT, PLEASE CLOSE IT FIRST\n";
}
void OpennedState::unlock(Door* door) {
	std::cout << "THE DOOR IS NOT LOCKED THEREFORE YOU CANNOT UNLOCK IT, PLEASE CLOSE THEN LOCK IT FIRST\n";
}