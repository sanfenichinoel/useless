#include "game.h"

Game::Game(int h, int x, int y): gra(x, y){
    srand((unsigned)time(NULL));
    this->hard = h;
}
Game::~Game(){
    delete bolck;
}

void Game::Control(){    
    int cnt = 10;
    while(1){
        bolck->show();
        Sleep(hard);

        if(OneOver()){
            GraAdd();
            break;
        }
        bolck->unshow();
        if(kbhit()){
            char op;
            op = getch();
            if((op == 'W' || op == 'w') && CanTurn() ){ bolck->control(1); }
            if((op == 'A' || op == 'a') && CanMove(-1)){ bolck->control(2); }
            if((op == 'S' || op == 's')){ bolck->control(3); }
            if((op == 'D' || op == 'd') && CanMove(1)){ bolck->control(4); }
        }else{
            bolck->control(3);
        } 
    }
}

bool Game::CanMove(int zy){
    if(zy > 0){
        for(auto i : bolck->v){
            if( (i.y + zy >= gra.size_y) || gra.gra[i.x][i.y + zy] != 0){
                return false;
            }
        }
    }else{
        for(auto i : bolck->v){
            if( (i.y + zy < 0) || gra.gra[i.x][i.y + zy] != 0){
                return false;
            }
        }
    }

    return true;
}

bool Game::CanTurn(){
    vector<Point> ne = bolck->turn();
    for (auto i : ne){
        if(i.x < 0 || i.x >= gra.size_x || i.y < 0 || i.y >= gra.size_y){
            return false;
        }
        if(gra.gra[i.x][i.y] != 0){
            return false;
        }
    }
    return true;
}

bool Game::OneOver(){
    for(auto i : bolck->v){
        if(i.x+2 >= gra.size_x || gra.gra[i.x+1][i.y] != 0){
            return true;
        }
    }
    return false;
}

void Game::GraAdd(){

    for(auto i : bolck->v){
        gra.gra[i.x][i.y] = i.color;
    }
    CheckRow();
}

bool Game::NewOne(){
    if(bolck != NULL){
        delete bolck;
    }

    int o = rand() % 5;
    if(o == 0){
        bolck = new O(gra.size_y / 2);
    }else if(o == 1){
        bolck = new L(gra.size_y / 2);
    }else if(o == 2){
        bolck = new I(gra.size_y / 2);
    }else if(o == 3){
        bolck = new Z(gra.size_y / 2);
    }else{
        bolck = new F(gra.size_y / 2);
    }
    
    return (!GameOver()) ;
}

void Game::GameBegin(){
    int cnt = 1;
    while(NewOne()){
        Control();
    }

    SetColor(4);
    SetCursorPosition(gra.size_x-1, 0);
    cout << "OVER" << endl;
}

bool Game::GameOver(){
    for(auto i : bolck->v){
        if(gra.gra[i.x][i.y] != 0){
            return true;
        }
    }
    return false;
}

void Game::CheckRow(){
    for(int r = gra.size_x - 1;r >= 0;r--){
        int cnt = 0;
        for(int j = 0;j < gra.size_y;j++){
            cnt += (int)(gra.gra[r][j] != 0);
        }
        if (cnt == gra.size_y){
            DeleteRow(r);
            r++;
            break;
        }
    }
}

void Game::DeleteRow(int r){
    gra.ClearRow(r);
}
