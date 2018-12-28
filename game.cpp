
//  game.cpp

#include "game.h"
using namespace std;

bool Minesweeper::shot(int x,int y, const MinesweeperField &field){
    if(field.hidden_field[x][y]) return false;
    int cnt=0; 
    for(int i=x-1;i<=x+1 && i<field.N;i++){  
        for(int j=y-1;j<=y+1 && j<field.N;j++){
            if (i>=0 && j>=0) cnt +=field.hidden_field[i][j];
        }
    }
    field.player_field[x][y] =cnt+0x30;
    return true;
}
void Minesweeper::FirstShot(MinesweeperField &field){
    int y;
    char x;
    cout<<"Выстрел:";
    cin>>x>>y;
    x=x-65;
    field.set_mine_count(x,y,field.count); 
    shot(x,y,field);
}

bool Minesweeper::ShotOrTag(MinesweeperField &field){
    int y;
    char x;
    int k=0;
    cout<<"1- Выстрел, 2- Пометить ячейку с миной"<<endl;
    cin>>k;
    if (k==2){
        cout<<"Ячейка:";
        cin>>x>>y;
        x=x-65;
        field.player_field[x][y]= 'm';
        return true;
    }
    else{
        cout<<"Выстрел:";
        cin>>x>>y;
        x=x-65;
        return shot(x,y,field);
    }
}
    
void Minesweeper::gam(MinesweeperField &field){
    
    field.clear_field();
    int k=1;
    bool f=true;
    int empty_cells=field.N*field.N-field.count; //колличество пустых ячеек
    
    field.show_field();
    FirstShot(field);
    do{
        field.show_field();
        f=ShotOrTag(field);
        k++;
    } while (f && !(k==empty_cells));
    if (k==empty_cells) cout<<"Вы выиграли"<<endl;
    if (!f) cout<<"GAME OVER"<<endl;
    
}

void Minesweeper::run() {
    int N = 10, count = 10;
    unsigned int k;
    bool answer = false;
    do{
        do{cout<<"Выберете уровень сложности: 1-Легкий,2-Обычный, 3-Сложный, 4-Особый (размер поля и колличество мин можно выбрать самостоятельно)"<<endl;
            cin>>k;
        }while (k>4);
        if (k==1) {N=5; count=5;};
        if (k==2) {N=10; count=10;};
        if (k==3) {N=20; count=50;};
        if (k==4){
            cout<<"Размер поля:";
            cin>>N;
            do{ cout<<"Колличество мин:";
                cin>>count;
            } while (count>N*N);
        }
        MinesweeperField f(N,count);
        gam(f); 
        cout<<"Сыграть еще раз?(1-да/0-нет)";
        cin>>answer;
    } while (answer);
}   
