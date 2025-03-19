#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    bool possible = false;

    if (a + b > c && a + c > b && b + c > a) possible = true;
    if (!possible && a + b > d && a + d > b && b + d > a) possible = true;
    if (!possible && a + c > d && a + d > c && c + d > a) possible = true;
    if (!possible && b + c > d && b + d > c && c + d > b) possible = true;

    if (possible) std::cout << "S" << std::endl;
    else std::cout << "N" << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}