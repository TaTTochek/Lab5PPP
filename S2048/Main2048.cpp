#include "Class.h"
#include "time.h"
#include <Windows.h>
#include <iostream>

int Game() {
    srand(time(NULL));
    system("chcp 1251");
    system("cls");

    mainGame2048 game;
    game.playGame2048();
    return 0;
}