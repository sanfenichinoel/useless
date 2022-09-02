#include <bits/stdc++.h>

int main()
{

        srand((unsigned)time(0));
    for(int i = 1;i <= 10;i++){
        int x = rand() + 1;
        int y = rand() + 1;

        std::cout << x << " " << y << std::endl;
    }
}