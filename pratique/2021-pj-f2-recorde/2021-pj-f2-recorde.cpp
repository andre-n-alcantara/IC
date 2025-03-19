#include <ctime>
#include <iostream>

int main() {
    int R, M, L;
    std::cin >> R >> M >> L;

    if (R < M)
        std::cout << "RM" << std::endl;
    else
        std::cout << "*" << std::endl;

    if (R < L)
        std::cout << "RO" << std::endl;
    else
        std::cout << "*" << std::endl;

    
return 0;
}