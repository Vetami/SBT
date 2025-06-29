#pragma once

#include <iostream>

enum State
{
	EMPTY,
	FULL,
	HIDDEN
};

class Cell
{
	State state;
public:
	Cell() { state = EMPTY; }
	Cell(State state) : state(state) {}

	void setState(State state);
	State getState();
	void showState();
};

void Cell::setState(State state)
{
	this->state = state;
}
State Cell::getState()
{
	return state;
}
void Cell::showState()
{
	switch (state)
	{
		case FULL: std::cout << '#'; break;
		case EMPTY: std::cout << '~'; break;
		case HIDDEN: std::cout << 'X'; break;
	}
}
