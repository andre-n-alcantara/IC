#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int a, b, c;
    std::cin >> a >> b >> c;

    if (a <= b && b <= c) {
        std::cout << b << std::endl;
    } else if (a <= c && c <= b) {
        std::cout << c << std::endl;
    } else {
        std::cout << a << std::endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}