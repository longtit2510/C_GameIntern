#include "Door.h"
#include "ClosedState.h"

//SET DOOR'S DEFAULT STATUS TO "CLOSED"
Door::Door():m_state{new ClosedState()}{}

void Door::setState(StateBase* newState) {
	m_state = newState;
}
void Door::displayCurrentState() {
	m_state->displayState();
}
void Door::open() {
	m_state->open(this);
}
void Door::close() {
	m_state->close(this);
}
void Door::lock() {
	m_state->lock(this);
}
void Door::unlock() {
	m_state->unlock(this);
}