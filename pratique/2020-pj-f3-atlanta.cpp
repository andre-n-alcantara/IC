#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int A, B;
    std::cin >> A >> B;

    for (int i = 1; i * i <= B; i++) {
        if ((i * i - 2 * i + 1) == B && (i - 2) * 2 == A) {
            if (i < i + 2) {
                std::cout << i << " " << i + 2 << std::endl;
            } else {
                std::cout << i + 2 << " " << i << std::endl;
            }
            
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
        }
    }

    std::cout << "-1 -1" << std::endl;

    return 0;
}