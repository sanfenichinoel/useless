#include <easyx.h>
#include <conio.h> 
#include <time.h>
#include <iostream>
#include <cmath>


class Point
{
private:
    int x, y;
    int size_x, size_y;
public:
    Point(int si_x, int si_y){
        NewOne(si_x, si_y);
        this->size_x = si_x;
        this->size_y = si_y;
    }
    void NewOne(int sx, int sy){
        switch(rand() % 4)
        {
            case 0:
                this->x = rand() % sx;
                this->y = 0;
                break;
            case 1:
                this->x = rand() % sx;
                this->y = sy;
                break;
            case 2:
                this->x = 0;
                this->y = rand() % sy;
                break;
            case 3:
                this->x = sx;
                this->y = rand() % sy;
                break;
        }
    }
    void Show(int target_x, int target_y){
        putpixel(x, y, BLACK);
        Move(target_x, target_y);
        putpixel(x, y, WHITE);
    }
    void Disappear(){
        putpixel(x, y, BLACK);
    }
    void Move(int target_x, int target_y){
        if(x == target_x && y == target_y){
            NewOne(size_x, size_y);
        }
        else{
            int dx = target_x - x;
            int dy = target_y - y;
            int dis = sqrt(dx * dx + dy * dy);
            int pus = 5;
            if(dx > 0){
                dx = std::min(dx, dx * pus / dis + 1);
            }else{
                dx = std::max(dx, dx * pus / dis - 1);
            }
            if(dy > 0){
                dy = std::min(dy, dy * pus / dis + 1);
            }else{
                dy = std::max(dy, dy * pus / dis - 1);
            }

            x += dx;
            y += dy;
        }
    }

};

const int pointNum = 10000;

int main() 
{
    srand((unsigned)time(NULL));
    const int six = 480, siy = 360;
    initgraph(six, siy);

    Point* p[pointNum + 5];
    for(int i = 0;i < pointNum;i++){
        p[i] = new Point(six, siy);
    }
    auto PointShow = [=](int x, int y)->void{
        for(int i = 0;i < pointNum;i++){
            p[i]->Show(x, y);
        }
    };

    ExMessage m;
    int mx, my;
    m = getmessage(EX_MOUSE | EX_KEY);
    mx = m.x, my = m.y;
    while(1){
        // Sleep(10);
        if(peekmessage(&m)){
            mx = m.x, my = m.y;
        }
        PointShow(mx, my);

        if(_kbhit())break;
    }


    getch();
    return 0;
}