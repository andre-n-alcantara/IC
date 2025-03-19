#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int d;
    std::cin >> d;
    int dist_emissor_acelerador = 3;
    int circunferencia_acelerador = 8;

    if(d <= dist_emissor_acelerador + circunferencia_acelerador) {
        std::cout << 1 << std::endl;
    } else if((d - dist_emissor_acelerador) % circunferencia_acelerador == 0) {
        std::cout << 2 << std::endl;
    } else {
        std::cout << 3 << std::endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}