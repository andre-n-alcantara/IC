#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int V, T;
    std::cin >> V >> T;
    
    for (int i = 0; i < T; i++) {
        int A;
        std::cin >> A;
        V = std::max(0, std::min(100, V + A));
    }
    
    std::cout << V << std::endl;
    
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}