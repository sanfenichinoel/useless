#include "tool.cpp"
#include "point.h"

#ifndef __DIAMOND__
#define __DIAMOND__

class Diamond
{
public:
    vector<Point> v;
    Diamond(int ex = 0);
    // 1 ↑, 2 ←, 3 ↓, 4 →
    void control(int id);
    virtual vector<Point> turn();
    void show();
    void unshow();
};


class O:public Diamond
{
public:
    O(int ex = 0);
    vector<Point> turn();
};

class L:public Diamond
{
public:
    L(int ex = 0);
};

class I:public Diamond
{
public:
    I(int ex = 0);
};

class Z:public Diamond
{
public:
    Z(int ex = 0);
};

class F:public Diamond
{
public:
    F(int ex = 0);
};


#endif