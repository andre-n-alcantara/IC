#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
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

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}