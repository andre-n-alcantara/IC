#include <iostream>

int main() {
    int N, A, L, P;
    std::cin >> N >> A >> L >> P;
    if (N <= A && N <= L && N <= P) {
        std::cout << "S" << std::endl;
    } else {
        std::cout << "N" << std::endl;
    }
    return 0;
}