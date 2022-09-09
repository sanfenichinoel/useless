#include "tool.cpp"
#include "point.h"

#ifndef __MYMAP__
#define __MYMAP__

class MyMap
{
public:
    int size_x, size_y;
    vector<vector<int> > gra;
    MyMap(int x = 30, int y = 20);
    void ShowMap();
    void ClearRow(int li);
    // void AddPoint(vector<int>& o);
};

#endif