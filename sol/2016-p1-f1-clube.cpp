#include <iostream>

int main() {
    int N, A, B, C, D, E, F, G;
    std::cin >> N >> A >> B >> C >> D >> E >> F >> G;
    if (A + B + C - D - E - F > N - G) {
        std::cout << "S" << std::endl;
    } else {
        std::cout << "N" << std::endl;
    }
    return 0;
}