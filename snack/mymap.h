#include "point.h"

#ifndef __MAP__
#define __MAP__

class MyMap
{
private:
    int size_x, size_y;
public:
    Point food;
    MyMap(int size_x, int size_y);
    void CreatANewFood();
    void ShowFood();
};

#endif