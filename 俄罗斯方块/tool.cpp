#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#ifndef __SETCURSOR__
#define __SETCURSOR__

//设置窗口大小
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



#endif
