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
    void control(int id);
    virtual void turn() = 0;
    void show();
    void unshow();
};


class O:public Diamond
{
public:
    O();
    void turn();
};

class L:public Diamond
{
public:
    L();
    void turn();
};

class I:public Diamond
{
public:
    I();
    void turn();
};

class Z:public Diamond
{
public:
    Z();
    void turn();
};

class F:public Diamond
{
public:
    F();
    void turn();
};


#endif