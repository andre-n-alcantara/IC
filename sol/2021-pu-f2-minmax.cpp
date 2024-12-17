#include <ctime>
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
    std::clock_t startTime = std::clock();
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

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}