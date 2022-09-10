#include "mymap.h"

MyMap::MyMap(int x, int y): gra(x, vector<int>(y, 0)) {
    SetWindowSize(x, y);
    this->size_x = x, this->size_y = y;
}

void MyMap::ClearRow(int li){
    for(int i = li; i > 0;i--){
        for(int j = 0;j < size_y;j++){
            gra[i][j] = gra[i-1][j];
        }
    }
    for(int j = 0;j < size_y;j++){
        gra[0][j] = 0;
    }

    ShowMap();
}

void MyMap::ShowMap(){
    for(int i = 0;i < size_x-1;i++){
        for(int j = 0;j < size_y;j++){
            // Point(i, j, gra[i][j]).ShowPoint();
            SetCursorPosition(i, j);
            SetColor(gra[i][j]);
            cout << "■";
        }
    }
}

