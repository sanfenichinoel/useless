//  GBK

#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <windows.h>

void ylsdd()
{
    POINT o;
    GetCursorPos(&o);
    ExMessage me;
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

int main()
{
    initgraph(480, 360);
    fillrectangle(180, 150, 300, 210);
    RECT r = {180, 150, 300, 210};
    drawtext(_T("点击此按钮") , &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    ExMessage m;
    while(1){
        m = getmessage(EX_MOUSE);
        if(m.message == WM_LBUTTONDOWN && m.x > 180 && m.x < 300 && m.y > 150 && m.y < 210){
            drawtext(_T(" Esc键退出 ") , &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            ylsdd();
            break;
        }
    }

    _getch();
    return 0;
}