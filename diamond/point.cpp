#include "point.h"

Point::Point(int x /* = 0 */, int y /* = 0 */, int color /* = 0 */){
    this->x = x, this->y = y, this->color = color;
}

void Point::ShowPoint(int cl /* = -1 */){
    SetCursorPosition(x, y);
    if(cl == -1){
        SetColor(color);
    }else{
        SetColor(cl);
    }
    std::cout << "■" << std::endl;
}