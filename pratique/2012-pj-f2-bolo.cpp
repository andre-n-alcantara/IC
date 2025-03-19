#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int A, B, C;
    std::cin >> A >> B >> C;
    int bolos = (A / 2) < (B / 3) ? (A / 2) < (C / 5) ? A / 2 : C / 5 : (B / 3) < (C / 5) ? B / 3 : C / 5;
    std::cout << bolos << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}