#include "diamond.h"

Diamond::Diamond(int ex):v(4){     
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
        v = turn();
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

vector<Point> Diamond::turn(){
    vector<Point> ne(4);
    for(int i = 0;i < 4;i++){
        int x = v[i].x - v[0].x;
        int y = v[i].y - v[0].y;
        ne[i] = {v[0].x + y, v[0].y - x, v[i].color};
    }
    return ne;
}


O::O(int ex):Diamond(){
    v[0] = {0, (ex - 1) + 0, 11};
    v[1] = {0, (ex - 1) + 1, 11};
    v[2] = {1, (ex - 1) + 0, 11};
    v[3] = {1, (ex - 1) + 1, 11};
}

vector<Point> O::turn(){
    return this->v;
}

L::L(int ex):Diamond(){
    v[0] = {2, (ex - 1) + 0, 2};
    v[1] = {1, (ex - 1) + 0, 2};
    v[2] = {0, (ex - 1) + 0, 2};
    v[3] = {2, (ex - 1) + 1, 2};
}

I::I(int ex):Diamond(){
    v[0] = {1, (ex - 1) + 0, 10};
    v[1] = {0, (ex - 1) + 0, 10};
    v[2] = {2, (ex - 1) + 0, 10};
    v[3] = {3, (ex - 1) + 0, 10};
}

Z::Z(int ex):Diamond(){
    v[0] = {0, (ex - 1) + 1, 6};
    v[1] = {0, (ex - 1) + 0, 6};
    v[2] = {1, (ex - 1) + 1, 6};
    v[3] = {1, (ex - 1) + 2, 6};
}

F::F(int ex):Diamond(){
    v[0] = {1, (ex - 1) + 1, 12};
    v[1] = {1, (ex - 1) + 0, 12};
    v[2] = {1, (ex - 1) + 2, 12};
    v[3] = {0, (ex - 1) + 1, 12};
}
