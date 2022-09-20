#include <deque>
#include "diamond.cpp"
#include "bird.cpp"

class Map
{
private:
	int size_x, size_y;
	std::deque<Diamond*> v;
    Bird bird;
public:
	Map(int size_x = 640, int size_y = 480);
	void Show();
	void Move();
	void Begin();
    void NewOne(int x, int y);
    bool Over();
    void GameOver();
};


Map::Map(int x, int y):bird(x / 2, y / 2){
	this->size_x = x;
	this->size_y = y;
	initgraph(x, y);
	srand((unsigned)time(NULL));

    NewOne(size_x, size_y);
}

void Map::Show(){
	cleardevice();
    
	for(auto i : v){
		i->Show();
	}
}

void Map::Move(){
    bool de = false;
	for(auto i : v){
		i->Move();
        de |= i->CanDel();
	}
    if(de){
        v.pop_front();
    }
}

void Map::Begin(){
    int ti = 0;
	while(1){
        if(Over()) break;
		ti++;
		Sleep(80);
		Show();
        bird.Begin();
		Move();
        if(ti == 20){
            NewOne(size_x, size_y);
            ti = 0;
        }
	}
    GameOver();
}

void Map::NewOne(int x, int y){
	Diamond* d = new Diamond(x, y);
	v.push_back(d);
}

bool Map::Over(){
    bool ds = false;
    for(auto i : v){
        ds |= bird.BirdDeath(i);
    }
    return ds;
}

void Map::GameOver(){
    RECT r = {0, 0, size_x-1, size_y-1};
    settextstyle(20, 0, _T("Consolas"));
	drawtext(_T("You Death, press Esc to exit"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    while(1){
        int ch = getch();
        if(ch == 0x1b) break;
    }
}