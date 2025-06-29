#pragma once

#include <vector>


// class Location
// {
// 	int x, y;
// public:
// 	Location(int x, int y) : x(x), y(y){}
// };

class Ship
{
	int size, x, y;
	bool isVertical;
	// std::vector<Location> locs;
	// void setLocation();
public:
	Ship(int size, int x, int y, bool isVertical) : size(size), x(x), y(x), isVertical(isVertical){}
	bool getIsVertical();
	int getSize();
	int getX();
	int getY();
	void setX(int i);
	void setY(int i);
	void setIsVertical(bool i);
};

// void Ship::setLocation()
// {
// 	if(isVertical)
// 	{
// 		for(int i = 0; i < size; i++)
// 		{
// 			locs.push_back(Location(x, y+i));
// 		}
// 	}
// 	if(!isVertical)
// 	{
// 		for(int i = 0; i < size; i++)
// 		{
// 			locs.push_back(Location(x+i, y));
// 		}
// 	}
// }
bool Ship::getIsVertical()
{
	return isVertical;
}
int Ship::getSize()
{
	return size;
}
int Ship::getX()
{
	return x;
}
int Ship::getY()
{
	return y;
}
void Ship::setX(int i)
{
	this->x = i;
}
void Ship::setY(int i)
{
	this->y = i;
}
void Ship::setIsVertical(bool i)
{
	this->isVertical = i;
}



