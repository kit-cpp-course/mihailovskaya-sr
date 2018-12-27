
//  field.h

#pragma once
#include <iostream>
#include "field.h"

//абстрактный класс игры
class Game
{
    virtual bool shot(int x,int y, const field &)=0;
    virtual void gam(field &)=0;
public:
    virtual void run() = 0;
};

//определенный класс игры для сапера
class Minesweeper: public Game
{
    
    /*
     *Дружественная функция для класса field, проверяет выстрел игрока
     *Если игрок попал в мину, возвращает false
     *Если игрок попал в пустое поле, считает мины вокруг и записывает значение в ячейку
     *@param int x строка выстрела
     *@param int y столбец выстрела
     */
    bool shot(int x,int y, const field &); 
    
    /*
     *Дружественная функция, которая запускает методы класса field в нужном порядке и "ведет игру"
     *В конце определяет выиграл игрок или проиграл
     */
    void gam(field &);
    
    
public:
    /*
     *запускает интерфейс игры и метод gam
     */
    void run();
};

