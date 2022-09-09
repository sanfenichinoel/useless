#include "tool.cpp"
#include "point.h"

#ifndef __DIAMOND__
#define __DIAMOND__

class Diamond
{
public:
    vector<Point> v;
    Diamond();
    // 1 ↑, 2 ←, 3 ↓, 4 →
    virtual void control(int id) = 0;
    void show();
    void unshow();
};


class O:public Diamond
{
public:
    O();
    void control(int id);
};


#endif