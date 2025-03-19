#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int Cv, Ce, Cs, Fv, Fe, Fs;
    std::cin >> Cv >> Ce >> Cs >> Fv >> Fe >> Fs;

    int Pc = 3 * Cv + Ce;
    int Pf = 3 * Fv + Fe;

    if (Pc > Pf) std::cout << "C";
    else if (Pc < Pf) std::cout << "F";
    else {
        if (Cs > Fs) std::cout << "C";
        else if (Cs < Fs) std::cout << "F";
        else std::cout << "=";
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}