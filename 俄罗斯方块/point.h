#include "tool.cpp"

#ifndef __POINT__
#define __POINT__
class Point
{
public:
    int x, y;
    int color;
    Point(int x = 0, int y = 0, int color = 0);
    void ShowPoint(int cl = -1);
};

#endif