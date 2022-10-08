#include <windows.h>
#include <stdio.h>
#include <conio.h>

// 设置窗口大小
void SetWindowSize(int lines, int cols)
{
    system("title sss");
    char cmd[30];
    sprintf(cmd, "mode con cols=%d lines=%d", cols * 2, lines);
    system(cmd);
}

// 设置指针位置
void SetCursorPosition(const int y, const int x)
{
    COORD position;
    position.X = x * 2;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

// 设置颜色
// 0：黑，1：深蓝，2：绿，3：浅蓝，4：红
// 5：紫，6：黄，7：白，8：灰，9：蓝，10：绿
// 11：天蓝，12：浅红，13：浅紫，14：浅黄，15：亮白
void SetColor(int colorID)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

// 这个键是否被点击（按下到松开） key是虚拟键码
bool IsPressThisKey(int key)
{
    return GetAsyncKeyState(key)&0x8000;
}

// 将鼠标卡在原处， esc键退出
void SteadyMouse()
{
    POINT o;
    GetCursorPos(&o);
    while(1){
        if(_kbhit()){
            char x = getch();
            if(x == 0x1b){
                break;
            }
        }
        SetCursorPos(o.x, o.y);
    }
}

// 你是我的神
void UTF8ToGBK(const char* strUTF8, char* iNeed)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, strUTF8, -1, NULL, 0);
	wchar_t* wszGBK = new wchar_t[len + 1];
	memset(wszGBK, 0, len * 2 + 2);
	MultiByteToWideChar(CP_UTF8, 0, strUTF8, -1, wszGBK, len);
	len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
	char* szGBK = new char[len + 1];
	memset(szGBK, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);
    strcpy(iNeed, szGBK);

	if (wszGBK) delete[] wszGBK;
	if (szGBK) delete[] szGBK;
}
