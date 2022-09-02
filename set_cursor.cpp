#include <windows.h>
#include <stdio.h>

#ifndef __SETCURSOR__
#define __SETCURSOR__

//设置窗口大小
void SetWindowSize(int lines, int cols)
{
    // system("title \u8fd9\u662f\u4e2a\u6807\u9898");
    system("title sssssss");
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
void SetColor(int colorID)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetBackColor()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            FOREGROUND_BLUE |
                            BACKGROUND_BLUE |
                            BACKGROUND_GREEN |
                            BACKGROUND_RED );
}

#endif
