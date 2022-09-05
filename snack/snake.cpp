#include "snake.h"

Snake::Snake(int x, int y): MyMap(x, y) {
    size_x = x, size_y = y;
    length = 1;
    direction = 4;
    Point a(1, 1);
    body.push_back(a);
    isMyBody[a] = true;
}

bool Snake::SnakeMove(){
    Point head = body.front();
    Point tail = body.back();
    int nx = head.x + dx[direction];
    int ny = head.y + dy[direction];
    Point nextPos(nx, ny);
    if(SnakeDeath(nextPos)){
        return true;
    }

    ShowPoint(nextPos, 7);
    body.push_front(nextPos);
    isMyBody[nextPos] = true;

    if(!SnakeEat(nextPos)){
        ShowPoint(tail, 0);
        body.pop_back();
        isMyBody[tail] = false;
    }

    return false;
}

void Snake::SnakeTurn(){
    char op;
    op = getch();
    if((op == 'W' || op == 'w') && direction != 3){ direction = 1; }
    if((op == 'A' || op == 'a') && direction != 4){ direction = 2; }
    if((op == 'S' || op == 's') && direction != 1){ direction = 3; }
    if((op == 'D' || op == 'd') && direction != 2){ direction = 4; }
}

bool Snake::SnakeDeath(Point nextPos){
    if(nextPos.x <= 0 || nextPos.x > size_x || nextPos.y <= 0 || nextPos.y > size_y){
        return true;
    }
    return isMyBody[nextPos];
}

bool Snake::SnakeEat(Point head){
    if(head == food){
        CreatANewFood();
        return true;
    }
    return false;
}

void Snake::SnakeBegin(){
    while(1){
        Sleep(80);
        if(kbhit()){
            SnakeTurn();
        }
        if(SnakeMove()){
            break;
        }
    }

    SetCursorPosition(size_x+2, 0);
    SetColor(4);
    cout << "Game Over" << endl;
}