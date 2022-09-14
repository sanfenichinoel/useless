#include <graphics.h>

#ifndef __SPHERE__
#define __SPHERE__

class Sphere
{
private:
    int size_x, size_y;
	int x, y, r;
	int a, v_x, v_y;
public:
	Sphere(int size_x, int size_y, int x, int y, int r = 10, int v_x = 1, int v_y = 0, int a = 1);
	void Move();
	void MayTurn();
    void Clear();
};


Sphere::Sphere(int si_x, int si_y, int x, int y, int r, int v_x, int v_y, int a){
    this->size_x = si_x;
    this->size_y = si_y;
	this->x = x;
	this->y = y;
	this->r = r;
	this->a = a;
	this->v_x = v_x;
    this->v_y = v_y;
}
void Sphere::Move(){
    MayTurn();
	y += (v_y + v_y + a) / 2;
	v_y += a;

    x += v_x;

	fillcircle(x, y, r);
}
void Sphere::MayTurn(){
    if(y + r + v_y >= size_y){
	    v_y = -v_y;
    }
    if(x + r + v_x >= size_x || x - r + v_x < 0){
        v_x = -v_x;
    }
}

void Sphere::Clear(){
    clearcircle(x, y, r+1);
}

#endif