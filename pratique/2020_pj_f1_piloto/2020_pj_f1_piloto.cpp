#include <ctime>
#include <iostream>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    if (B - A < C - B) {
        std::cout << 1 << std::endl;
    } else if (B - A > C - B) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }

    
return 0;
}