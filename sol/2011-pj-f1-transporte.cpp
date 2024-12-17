#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int A, B, C, X, Y, Z;
    std::cin >> A >> B >> C;
    std::cin >> X >> Y >> Z;

    if (C > Z) {
        std::cout << 0 << std::endl;
    } else {
        int width = X / A;
        int length = Y / B;
        std::cout << width * length << std::endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}