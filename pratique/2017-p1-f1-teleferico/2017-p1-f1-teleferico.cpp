#include <ctime>
#include <iostream>

int main() {
    int C, A;
    std::cin >> C >> A;

    int viagens = (A + C - 1) / C;

    std::cout << viagens << std::endl;

    
return 0;
}