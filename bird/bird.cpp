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

public:
	Bird(int x, int y, int r = 10);
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
	solidcircle(pos_x, pos_y, r);
}

void Bird::Down(){
	clearcircle(pos_x, pos_y, r);
	pos_y += 10;
	solidcircle(pos_x, pos_y, r);
}

void Bird::Up(){
	clearcircle(pos_x, pos_y, r);
	pos_y -= 20;
	solidcircle(pos_x, pos_y, r);
}

void Bird::Begin(){
	if(kbhit()){
		getch();
		// Up();
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