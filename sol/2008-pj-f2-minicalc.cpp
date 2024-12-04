
#include <iostream>

int main() {
    int N, D, Q;
    std::cin >> N >> D >> Q;

    int maxVal = 1 << N;

    if (D >= maxVal || Q >= maxVal) {
        std::cout << "IMPOSSIVEL" << std::endl;
        return 0;
    }

    int gcd = __gcd(D, Q);
    D /= gcd;
    Q /= gcd;

    while (D >= maxVal || Q >= maxVal) {
        D /= 2;
        Q /= 2;
    }

    std::cout << D << " " << Q << std::endl;

    return 0;
}
