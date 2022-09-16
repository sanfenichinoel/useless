#include <easyx.h>
#include <time.h>

#ifndef __DIA__
#define __DIA__

class Diamond
{
private:
    int l, r, u, d;
    int si_x, si_y;

public:
    Diamond(int si_x, int si_y);
    void Show();
    void Move();
    bool CanDel();

    friend class Bird;
};


Diamond::Diamond(int x, int y){
    this->si_x = x;
    this->si_y = y;
    this->l = si_x;
    this->r = l + 20;
    this->u = rand() % (si_y / 2) + (si_y / 4) - 50;
    this->d = u + 100;
}

void Diamond::Show(){
    fillrectangle(l, 0, r, u);
    fillrectangle(l, d, r, si_y);
}

void Diamond::Move(){
    l -= 10;
    r -= 10;
}

bool Diamond::CanDel(){
    return r < 0;
}

#endif