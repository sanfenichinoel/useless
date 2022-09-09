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

O::O():Diamond(){
    v[0] = {0, 0, 1};
    v[1] = {0, 1, 1};
    v[2] = {1, 0, 1};
    v[3] = {1, 1, 1};
}

void O::control(int id){
    switch (id)
    {
    case 1:
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