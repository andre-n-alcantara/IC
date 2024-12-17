#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int X, Y, L1, H1, L2, H2;
    std::cin >> X >> Y >> L1 >> H1 >> L2 >> H2;

    if ((L1 <= X && H1 <= Y) || (H1 <= X && L1 <= Y) ||
        (L2 <= X && H2 <= Y) || (H2 <= X && L2 <= Y) ||
        (L1 + L2 <= X && max(H1, H2) <= Y) || (H1 + H2 <= X && max(L1, L2) <= Y) ||
        (L1 + H2 <= X && max(H1, L2) <= Y) || (H1 + L2 <= X && max(H2, L1) <= Y))
        std::cout << "S" << std::endl;
    else
        std::cout << "N" << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}