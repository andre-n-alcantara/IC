#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int N, D, Q;
    std::cin >> N >> D >> Q;

    int maxVal = 1 << N;

    if (D >= maxVal || Q >= maxVal) {
        std::cout << "IMPOSSIVEL" << std::endl;
        
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
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