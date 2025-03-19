#include <ctime>
#include <iostream>
#include <cmath>

int main() {
    std::clock_t startTime = std::clock();
    int A, B;
    std::cin >> A >> B;
    int count = 0;
    for (int i = A; i <= B; i++) {
        double cubeRoot = cbrt(i);
        double sqrtRoot = sqrt(i);
        if (cubeRoot == (int)cubeRoot && sqrtRoot == (int)sqrtRoot) {
            count++;
        }
    }
    std::cout << count << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}