#include <easyx.h>
#include <windows.h>
#include <conio.h>
#include "diamond.cpp"

#ifndef __BIRD__
#define __BIRD__
class Bird
{
private:
	int pos_x, pos_y, r;
	IMAGE img;
	IMAGE img_turn;

public:
	Bird(int x, int y, int r = 15);
	void Down();
	void Up();
	void Begin();
	bool BirdDeath(Diamond* o);
};


Bird::Bird(int x, int y, int r){
	this->pos_x = x;
	this->pos_y = y;
	this->r = r;
    initgraph(x, y);
	loadimage(&img, (LPCTSTR)"./bird.png", 0, 0);
	Resize(&img, 30, 30);
	rotateimage(&img_turn, &img, 0.5);
}

void Bird::Down(){
	pos_y += 10;
	putimage(pos_x - r, pos_y - r, &img);
}

void Bird::Up(){
	pos_y -= 20;
	putimage(pos_x - r, pos_y - r, &img_turn);
}

void Bird::Begin(){
	if(kbhit()){
		getch();
		Up();
	}else{
		Down();
	}
}

bool Bird::BirdDeath(Diamond* o){
	if(pos_x + r > o->l && pos_x - r < o->r){
		return !(pos_y + r < o->d && pos_y - r > o->u);
	}
	return false;
}

#endif