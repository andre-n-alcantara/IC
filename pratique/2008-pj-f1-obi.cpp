#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int N, P, X, Y, cont = 0;
    std::cin >> N >> P;
    for(int i = 0; i < N; i++) {
        std::cin >> X >> Y;
        if(X + Y >= P) cont++;
    }
    std::cout << cont << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}