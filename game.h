
//  field.h

#pragma once
#include <iostream>

class game
{
    class field;
    
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
    
    class field
    {
    public:
        int N;
        int count;
        bool **hidden_field; //скрытое поле с раставленными минами
        char **player_field; //поле, которое покаазывается игроку
    
        //конструктор класса
        field(int N, int count);
        //деструктор класса
        ~field();
    
        /*
         *подготавливает чистое поле
         */
        void clear_field();
    
        /*
         *ставит мины до тех пор, пока не поставит нужное колличество
         *Первый выстрел не может быть проигрышным, поэтому на вход подаются не только колличество мин, но и координаты первого выстрела
         *@param xx строка первого выстрела
         *@param yy столбец первого выстрела
         *@param count кол-во мин на поле
         */
        void set_mine_count(int xx,int yy, int count);
    
        /*
         *вывод поля
         */
        void show_field();
        
        friend bool shot(int x,int y, const field &);
        friend void gam(field &);
    };
public:
    /*
     *запускает интерфейс игры и метод gam
     */
    void run();
};

