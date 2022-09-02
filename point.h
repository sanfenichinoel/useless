
#ifndef __POINT__
#define __POINT__

struct Point
{
    // int color;
    int x, y;
    Point(int x = 0, int y = 0) {this->x = x, this->y = y;}
    bool operator<(const Point& o)const {
        if(x != o.x){
            return x < o.x;
        }
        return y < o.y;
    }
    bool operator==(const Point& o)const{
        return x == o.x && y == o.y;
    }
};

#endif