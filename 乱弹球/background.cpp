
#ifndef __BACKGROUND__
#define __BACKGROUND__

class BackGround
{
private:
	int size_x, size_y; 
public:
	BackGround(int x = 420, int y = 360);
	int GetX();
	int GetY();
};
BackGround::BackGround(int x, int y){
	this->size_x = x;
	this->size_y = y;
}
int BackGround::GetX(){
	return size_x;
}
int BackGround::GetY(){
	return size_y;
}

#endif