#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int A, B;
    std::cin >> A >> B;
    A %= 3;
    B %= 3;
    if (B == A) B = (B + 1) % 3;
    std::cout << (3 - A - B) % 3 + 1 << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}