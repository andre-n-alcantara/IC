
#include <iostream>

int main() {
    int L;
    std::cin >> L;
    int pedacos = 1;
    while (L >= 2) {
        pedacos *= 4;
        L /= 2;
    }
    std::cout << pedacos << std::endl;
    return 0;
}
