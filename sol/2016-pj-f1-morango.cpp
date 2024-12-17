#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int comprimento1, largura1, comprimento2, largura2;
    std::cin >> comprimento1 >> largura1 >> comprimento2 >> largura2;

    int area1 = comprimento1 * largura1;
    int area2 = comprimento2 * largura2;

    if (area1 > area2) {
        std::cout << area1 << std::endl;
    } else {
        std::cout << area2 << std::endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}