#include <ctime>
#include <iostream>

int main() {
    int L, C;
    std::cin >> L >> C;

    int tipo1 = (L * C) - 4;
    int tipo2 = (L + C - 2) * 2 - 4;

    std::cout << tipo1 << std::endl;
    std::cout << tipo2 << std::endl;

    
return 0;
}