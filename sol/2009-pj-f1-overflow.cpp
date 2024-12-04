
#include <iostream>

int main() {
    int N, P, Q;
    char C;
    std::cin >> N >> P >> C >> Q;

    if (C == '+') {
        if (P + Q > N) {
            std::cout << "OVERFLOW" << std::endl;
        } else {
            std::cout << "OK" << std::endl;
        }
    } else if (C == '*') {
        if (static_cast<long long>(P) * Q > N) {
            std::cout << "OVERFLOW" << std::endl;
        } else {
            std::cout << "OK" << std::endl;
        }
    }

    return 0;
}
