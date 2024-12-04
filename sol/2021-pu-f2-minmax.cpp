#include <iostream>
#include <vector>

int somaDigitos(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int S, A, B, min = A, max = A;
    std::cin >> S >> A >> B;

    for (int i = A; i <= B; i++) {
        if (somaDigitos(i) == S) {
            if (i < min) min = i;
            if (i > max) max = i;
        }
    }

    std::cout << min << std::endl;
    std::cout << max << std::endl;

    return 0;
}