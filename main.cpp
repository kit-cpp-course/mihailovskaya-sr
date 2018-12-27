//
//  main.cpp
//  сапер
//
//  Created by Софья Михайловская on 15/12/2018.
//  Copyright © 2018 Софья Михайловская. All rights reserved.
//

#include "game.h"
#include <time.h>
using namespace std;

int main() {
    srand(time(NULL));
    
    Game * game = new Minesweeper();
    game->run();
    delete game;
    return 0;
}
