#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int N;
    std::cin >> N;

    if(N >= 90) std::cout << "A";
    else if(N >= 75) std::cout << "B";
    else if(N >= 60) std::cout << "C";
    else if(N >= 40) std::cout << "D";
    else std::cout << "E";

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}