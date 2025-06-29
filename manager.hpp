#pragma once

#include "field.hpp"
#include <vector>

Field field;

class Manager
{
    std::vector<Ship> ships;
public:
    Manager(int size, int amount)
    {
        for (int i = 0; i < amount; i++)
        {
            ships.push_back(Ship(size, -10, -10, 0));
        }
    }
    Manager(){};

    void addShip(Ship ship);
    void addShip(int size, int amount);
    int checkCollision(Ship ship);
    int checkCollision(int x, int y, int size, bool isVertical);
    Ship &getShip(int i);
    int getAmount();
    int setPosition(int shipCount, int x, int y, bool isVertical);
};

void Manager::addShip(Ship ship) //Добавление кораблей с проверкой колизии
{
    if(!checkCollision(ship))
    {
        ships.push_back(ship);
        field.addShip(ship);
    }
    else{return;}
}
void Manager::addShip(int size, int amount) //Добавление кораблей без проверок колизии 
{
    for (int i = 0; i < amount; i++)
        {
            ships.push_back(Ship(size, -10, -10, 0));
        }    
}
int Manager::checkCollision(Ship ship) //Проверка колизии кораблей 
{
    std::vector<Ship>::iterator ptr = ships.begin();
    while(ptr != ships.end())
    {
        if(ship.getIsVertical())
            for (int i = -1; i <= ship.getSize(); i++)
                for (int j = -1; j <= 1; j++)
                    if(ship.getX()+j == ptr->getX() && ship.getY()+i == ptr->getY()) return 1;
        if(!ship.getIsVertical())
            for (int i = -1; i <= ship.getSize(); i++)
                for (int j = -1; j <= 1; j++)
                    if(ship.getX()+i == ptr->getX() && ship.getY()+j == ptr->getY()) return 1;
    }
    return 0;
}
int Manager::checkCollision(int x, int y, int size, bool isVertical) //Проверка колизии кораблей 
{
    std::vector<Ship>::iterator ptr = ships.begin();
    while(ptr != ships.end())
    {
        if(isVertical)
            for (int i = -1; i <= size; i++)
                for (int j = -1; j <= 1; j++)
                    if(x+j == ptr->getX() && y+i == ptr->getY()) return 1;
        if(!isVertical)
            for (int i = -1; i <= size; i++)
                for (int j = -1; j <= 1; j++)
                    if(x+i == ptr->getX() && y+j == ptr->getY()) return 1;
        ptr++;
    }
    return 0;
}
Ship &Manager::getShip(int i) //Получение корабля
{
    return ships[i];
}
int Manager::getAmount() //Получение количества кораблей
{
    return ships.size();
}
int Manager::setPosition(int shipCount, int x, int y, bool isVertical) //Установка позиции корабля с проверкой колизии
{
    if(checkCollision(x, y, ships[shipCount].getSize(), isVertical)) return 0;
    else
    {
        ships[shipCount].setX(x);
        ships[shipCount].setY(y);
        ships[shipCount].setIsVertical(isVertical);
        field.addShip(ships[shipCount]);
        return 1;
    }
}
    
