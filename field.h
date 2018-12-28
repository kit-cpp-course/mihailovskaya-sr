
//  field.h

#include <iostream>
// абстрактный класс поля
class Field
{
    virtual void clear_field()=0;
    
    virtual void set_mine_count(int xx,int yy, int count)=0;
    
    virtual void show_field()=0;
};

// класс поля для игры сапер
class MinesweeperField: public Field
{
private:
    int N;
    int count;
    bool **hidden_field; //скрытое поле с раставленными минами
    char **player_field; //поле, которое покаазывается игроку
    
    //конструктор класса
    MinesweeperField(int N, int count);
    //конструктор копирования
    MinesweeperField(const MinesweeperField & f);
    //Перегруженная операция присваивания
    MinesweeperField & operator=(const MinesweeperField & f);
    //деструктор класса
    ~MinesweeperField();
    
    /* дружественный класс
     * Minesweeper может использовать содержимое MinesweeperField
     */
    friend class Minesweeper;
    
    /*
     *Подготавливает чистое поле
     */
    void clear_field();
    
    /*
     *Ставит мины до тех пор, пока не поставит нужное колличество
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
    };

