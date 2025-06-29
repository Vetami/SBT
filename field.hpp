#pragma once

#include <vector>
#include <iostream>
#include "ship.hpp"
#include "Cell.hpp"



class Field
{
	int width, height;
	std::vector<std::vector<Cell>> grid;
public:
	Field(int width, int height) :width(width), height(height) { this->resize(); }
	Field(){}
	void resize();
	void resize(int width, int height);
	void addShip(Ship ship);
	void showField();
};

void Field::resize()
{
	grid.resize(width);
	for (size_t x = 0; x < grid.size(); x++)
	{
		grid[x].resize(height);
	}
}
void Field::resize(int width, int height)
{
	this->width = width;
	this->height = height;
	grid.resize(width);
	for (int x = 0; x < grid.size(); x++)
	{
		grid[x].resize(height);
	}
}
void Field::addShip(Ship ship)
{
	if (ship.getIsVertical())
	{
		for (int i = 0; i < ship.getSize(); i++)
		{
			grid[ship.getX()][ship.getY() + i].setState(FULL);
		}
	}
	else if (!ship.getIsVertical())
	{
		for (int i = 0; i < ship.getSize(); i++)
		{
			grid[ship.getX() + i][ship.getY()].setState(FULL);
		}
	}
}
void Field::showField()
{
	std::cout << ' ';
	for (int x = 0; x < width; x++)
		std::cout << ' ' << 0 + x;
	for (int y = 0; y < height; y++)
	{
		std::cout << ' ';
		std::cout << '\n';
		std::cout << 0 + y << ' ';
		for (int x = 0; x < width; x++)
		{
			grid[x][y].showState();
			std::cout << ' ';
		}
	}
	std::cout << '\n';
}