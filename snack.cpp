#include "snack.h"

Snack::Snack(int x, int y): MyMap(x, y) {
    size_x = x, size_y = y;
    length = 1;
    direction = 4;
    Point a(1, 1);
    body.push_back(a);
    isMyBody[a] = true;
}

bool Snack::SnackMove(){
    Point head = body.front();
    Point tail = body.back();
    int nx = head.x + dx[direction];
    int ny = head.y + dy[direction];
    Point nextPos(nx, ny);
    if(SnackDeath(nextPos)){
        return true;
    }

    ShowPoint(nextPos, 7);
    body.push_front(nextPos);
    isMyBody[nextPos] = true;

    if(!SnackEat(nextPos)){
        ShowPoint(tail, 0);
        body.pop_back();
        isMyBody[tail] = false;
    }

    return false;
}

void Snack::SnackTurn(){
    char op;
    op = getch();
    if((op == 'W' || op == 'w') && direction != 3){ direction = 1; }
    if((op == 'A' || op == 'a') && direction != 4){ direction = 2; }
    if((op == 'S' || op == 's') && direction != 1){ direction = 3; }
    if((op == 'D' || op == 'd') && direction != 2){ direction = 4; }
}

bool Snack::SnackDeath(Point nextPos){
    if(nextPos.x <= 0 || nextPos.x > size_x || nextPos.y <= 0 || nextPos.y > size_y){
        return true;
    }
    return isMyBody[nextPos];
}

bool Snack::SnackEat(Point head){
    if(head == food){
        CreatANewFood();
        return true;
    }
    return false;
}

void Snack::SnackBegin(){
    while(1){
        Sleep(80);
        if(kbhit()){
            SnackTurn();
        }
        if(SnackMove()){
            break;
        }
    }

    SetCursorPosition(size_x+2, 0);
    SetColor(4);
    cout << "Game Over" << endl;
}