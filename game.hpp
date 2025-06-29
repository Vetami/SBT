#pragma once

#include "manager.hpp"
#include "field.hpp"

Manager manager;

class Game
{
    int input = 0;
public:
    Game();
    int mainMenu();
    void setField();
    void addShips();
    void setShips();
};

int Game::mainMenu() //Вывод главного меню
{
    std::cout << "1. Начать игру \n";
    std::cin >> input;
    return input;
}
void Game::setField() //Установка размера поля
{
    std::cout << "Введите широту поля:\n";
    int width = 0;
    std::cin >>width; 
    std::cout << "Введите высоту поля:\n";
    int height = 0;
    std::cin >>height;
    field.resize(width,height);
    field.showField();
}
void Game::addShips() //Добавление кораблей(размер, количество)
{
    std::cout << "Сколько расставить 1-палубных кораблей?\n";
    std::cin >> input;
    manager.addShip(1, input);
    std::cout << "Сколько расставить 2-палубных кораблей?\n";
    std::cin >> input;
    manager.addShip(2, input);
    std::cout << "Сколько расставить 3-палубных кораблей?\n";
    std::cin >> input;
    manager.addShip(3, input);
    std::cout << "Сколько расставить 4-палубных кораблей?\n";
    std::cin >> input;
    manager.addShip(4, input);
}
void Game::setShips()  //Смена местоположения кораблей
{
    for(int shipCount = 0; shipCount < manager.getAmount(); shipCount++)
    {
        int x = 0;
        int y = 0;
        bool isVertical = 0;
            if(manager.getShip(shipCount).getSize() == 1)
            {
                while(1)
                {
                    std::cout << "Расстановка 1-палубного корабля по x: \n";
                    std::cin >> x;
                    std::cout << "Расстановка 1-палубного корабля по y: \n";
                    std::cin >> y;
                    std::cout << "Расстановка 1-палубного корабля по вертикали-1: \n";
                    std::cin >> isVertical;
                    if(!manager.checkCollision(x, y, manager.getShip(shipCount).getSize(), isVertical))
                        {
                        manager.setPosition(shipCount, x, y, isVertical);
                        break;
                        }
                    else{std::cout << "Ошибка расстановки!\n";}
                }
            }
        
            if(manager.getShip(shipCount).getSize() == 2)
            {
                while(1)
                {
                    std::cout << "Расстановка 2-палубного корабля по x: \n";
                    std::cin >> x;
                    std::cout << "Расстановка 2-палубного корабля по y: \n";
                    std::cin >> y;
                    std::cout << "Расстановка 2-палубного корабля по вертикали-1: \n";
                    std::cin >> isVertical;
                    if(!manager.checkCollision(x, y, manager.getShip(shipCount).getSize(), isVertical))
                            {
                            manager.setPosition(shipCount, x, y, isVertical);
                            break;
                            }
                        else{std::cout << "Ошибка расстановки!\n";}
                }
            }
            if(manager.getShip(shipCount).getSize() == 3)
            {
                    while(1)
                    {
                        std::cout << "Расстановка 3-палубного корабля по x: \n";
                        std::cin >> x;
                        std::cout << "Расстановка 3-палубного корабля по y: \n";
                        std::cin >> y;
                        std::cout << "Расстановка 3-палубного корабля по вертикали-1: \n";
                        std::cin >> isVertical;
                        if(!manager.checkCollision(x, y, manager.getShip(shipCount).getSize(), isVertical))
                                {
                                manager.setPosition(shipCount, x, y, isVertical);
                                break;
                                }
                            else{std::cout << "Ошибка расстановки!\n";}
                    }
            }
            if(manager.getShip(shipCount).getSize() == 4)
            {
                while(1)
                {
                    std::cout << "Расстановка 4-палубного корабля по x: \n";
                    std::cin >> x;
                    std::cout << "Расстановка 4-палубного корабля по y: \n";
                    std::cin >> y;
                    std::cout << "Расстановка 4-палубного корабля по вертикали-1: \n";
                    std::cin >> isVertical;
                    if(!manager.checkCollision(x, y, manager.getShip(shipCount).getSize(), isVertical))
                            {
                            manager.setPosition(shipCount, x, y, isVertical);
                            break;
                            }
                    else{std::cout << "Ошибка расстановки!\n";}
                }
            }
        field.showField();
    }
}
Game::Game()
{
    {
        if(mainMenu())
            {
                setField();
                addShips();
                setShips();
            }
        else
        {
            exit(0);
        }
    }
}
