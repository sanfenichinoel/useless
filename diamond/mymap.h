#include "tool.cpp"
#include "point.h"

#ifndef __MYMAP__
#define __MYMAP__

class MyMap
{
public:
    int size_x, size_y;
    vector<vector<int> > gra;
    MyMap(int x, int y);
    void ShowMap();
    void ClearRow(int li);
};

#endif