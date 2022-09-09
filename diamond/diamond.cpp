#include "diamond.h"

Diamond::Diamond():v(4){     
}

void Diamond::show(){
    for(auto i : v){
        i.ShowPoint();
    }
}

void Diamond::unshow(){
    for(auto i : v){
        i.ShowPoint(0);
    }
}

void Diamond::control(int id){
    switch (id)
    {
    case 1:
        turn();
        break;
    case 2:
        for(int i = 0;i < 4;i++){
            v[i].y--;
        }
        break;
    case 3:
        for(int i = 0;i < 4;i++){
            v[i].x++;
        }
        break;
    case 4:
        for(int i = 0;i < 4;i++){
            v[i].y++;
        }
        break;
    }
}

O::O():Diamond(){
    v[0] = {0, 0, 11};
    v[1] = {0, 1, 11};
    v[2] = {1, 0, 11};
    v[3] = {1, 1, 11};
}

void O::turn(){
    return;
}


L::L():Diamond(){
    v[0] = {2, 0, 2};
    v[1] = {1, 0, 2};
    v[2] = {0, 0, 2};
    v[3] = {2, 1, 2};
}

void L::turn(){
    return;
}


I::I():Diamond(){
    v[0] = {1, 0, 10};
    v[1] = {0, 0, 10};
    v[2] = {2, 0, 10};
    v[3] = {3, 0, 10};
}

void I::turn(){
    return;
}


Z::Z():Diamond(){
    v[0] = {0, 1, 6};
    v[1] = {0, 0, 6};
    v[2] = {1, 1, 6};
    v[3] = {1, 2, 6};
}

void Z::turn(){
    return;
}

F::F():Diamond(){
    v[0] = {0, 1, 12};
    v[1] = {0, 0, 12};
    v[2] = {1, 1, 12};
    v[3] = {1, 2, 12};
}

void F::turn(){
    return;
}
