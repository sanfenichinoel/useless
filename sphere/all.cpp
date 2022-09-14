#include "sphere.cpp"
#include <conio.h>
#include <time.h>
#include <vector>

#ifndef __ALL__
#define __ALL__

class All
{
private:
    int n, si_x, si_y;
    std::vector< Sphere* > sp;
public:
    All(int si_x = 420, int si_y = 360, int n = 1);
    void NewASphere();
    void Begin();
};

All::All(int x, int y, int n){
    initgraph(x, y);
    srand((unsigned)time(NULL));
    this->n = n;
    this->si_x = x;
    this->si_y = y;

    for(int i = 1;i <= n;i++){
        int bx = rand() % (x / 2) + (x / 4);
        int by = rand() % y / 2 + 1;
        int r = rand() % 20 + 5;
        int v_x = rand() % 10 + 1;
        int v_y = rand() % 10 + 1;
        // int a = rand() % 5 + 1;
        int a = 5;
        Sphere* ball = new Sphere(x, y, bx, by, r, v_x, v_y, a);
        sp.push_back(ball);
    }
}

void All::Begin(){
    while(1){
        for(auto i : sp){
            i->Clear();
            i->Move();   
        }

        Sleep(25);
        // cleardevice();
    } 
}

#endif
