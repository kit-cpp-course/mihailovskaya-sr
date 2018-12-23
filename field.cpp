
//  field.cpp

#include "game.h"
#include <ctime>
using namespace std;

game::field::field(int aN, int aCount){
     N=aN;
    count = aCount;
    hidden_field = new bool*[N];
    for(int i = 0; i < N; i++){
        hidden_field[i] = new bool[N];
    }
    player_field = new char*[N];
    for(int i = 0; i < N; i++){
        player_field[i] = new char[N];
   }
}

game::field::~field(){
    for (int i = 0; i < N; i++)
        delete [] hidden_field[i];
    delete [] hidden_field;
    
    for (int i = 0; i < N; i++)
        delete [] player_field[i];
    delete[] player_field;
}



void game::field::clear_field(){
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<N; j++){
            player_field[i][j]='*';
            hidden_field[i][j]=0;
        }
    }
}

void game::field::set_mine_count(int xx,int yy, int count){

    for(int i=0;i<count;){
        int x=rand()%N;
        int y=rand()%N;
        if(!hidden_field[x][y] && !(x==xx & y==yy) ){
            hidden_field[x][y]=1;
            i++;
        }
    }
}

void game::field::show_field(){
    cout<<"  ";
    for(int i=0;i<N;i++){
        cout<<i<<" ";
    }
    
    cout << endl<< string(N*2+2, '-')<<endl;
    for (int i=0;i<N;i++){
        cout<<(char)(i+65)<<'|';
        for(int j=0;j<N;j++){
            cout<<player_field[i][j]<<" ";
        }
        cout<<endl;
    }
}

