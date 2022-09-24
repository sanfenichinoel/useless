#include "diamond.h"
#include "mymap.h"
#include <conio.h>
#include <time.h>
#include <stdlib.h>

#ifndef __GAME__
#define __GAME__

class Game
{
private:
    Diamond* bolck;
    MyMap gra;
    int hard;

public:
    Game(int hard = 150, int x = 25, int y = 16);
    ~Game();
    void Control();
    // -1, 1
    bool CanMove(int zy);
    bool CanTurn();
    bool OneOver();
    void GraAdd();
    bool NewOne();
    void GameBegin();
    bool GameOver();
    void CheckRow();
    void DeleteRow(int row);
};

#endif