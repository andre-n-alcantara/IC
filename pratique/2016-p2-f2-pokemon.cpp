#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int N, X, Y, Z;
    std::cin >> N >> X >> Y >> Z;

    int count = 0;
    if (N >= X) {
        N -= X;
        count++;
    }
    if (N >= Y) {
        N -= Y;
        count++;
    }
    if (N >= Z) {
        N -= Z;
        count++;
    }

    std::cout << count << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}