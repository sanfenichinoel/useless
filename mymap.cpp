#include "mymap.h"
#include "set_cursor.cpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

MyMap::MyMap(int x, int y){
    srand((unsigned)time(0));
    this->size_x = x + 2;
    this->size_y = y + 2;
    SetWindowSize(size_x + 2, size_y);

    for(int i = 0; i < size_x;i++){
        ShowPoint(Point(i, 0), 6);
        ShowPoint(Point(i, size_x-1), 6);
    }
    for(int i = 0; i < size_y;i++){
        ShowPoint(Point(0, i), 6);
        ShowPoint(Point(size_y-1, i), 6);
    }

    CreatANewFood();
}

void MyMap::CreatANewFood(){
    int x = rand() % (size_x - 2) + 1;
    int y = rand() % (size_y - 2) + 1;
    food.x = x;
    food.y = y;
    ShowFood();
}

void MyMap::ShowFood(){
    ShowPoint(food, 4);
}