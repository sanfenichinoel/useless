#include <queue>
#include <map>
#include <iostream>
#include <conio.h>
#include "point.h"
#include "mymap.h"
#include "set_cursor.cpp"
using namespace std;

#ifndef __SNACK__
#define __SNACK__

class Snake: public MyMap
{
private:
    int length;
    int direction;  // 1 ↑, 2 ←, 3 ↓, 4 →
    std::deque<Point> body;
    int size_x, size_y;
    std::map<Point, bool> isMyBody;

    int dx[5] = {0, -1, 0, 1, 0};
    int dy[5] = {0, 0, -1, 0, 1};

public:
    Snake(int size_x, int size_y);
    void SnakeShow();
    bool SnakeMove();
    void SnakeTurn();
    bool SnakeEat(Point head);
    bool SnakeDeath(Point nextPos);
    void SnakeBegin();
};

#endif
