
#include <iostream>

int main() {
    int A, M;
    std::cin >> A >> M;
    if (A + M <= 50) {
        std::cout << "S" << std::endl;
    } else {
        std::cout << "N" << std::endl;
    }
    return 0;
}
