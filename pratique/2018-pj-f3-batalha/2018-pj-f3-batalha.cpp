#include <ctime>
#include <iostream>

int main() {
    int A1, D1, A2, D2;
    std::cin >> A1 >> D1 >> A2 >> D2;

    if ((A1 == D2) && (A2 != D1)) {
        std::cout << 2 << std::endl;
    } else if ((A2 == D1) && (A1 != D2)) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    
return 0;
}