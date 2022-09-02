#include "head.h"
using namespace std;
int main()
{
    int x = 30, y = 30;
    SetConsoleOutputCP(65001);
    Snack s(x, y);
    s.SnackBegin();

    system("pause");
    return 0;
}