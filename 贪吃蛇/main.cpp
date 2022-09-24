#include "head.h"
using namespace std;
int main()
{
    int x = 30, y = 30;
    SetConsoleOutputCP(65001);
    Snake s(x, y);
    s.SnakeBegin();

    system("pause");
    return 0;
}