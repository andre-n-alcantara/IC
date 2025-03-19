#include <ctime>
#include <iostream>
#include <string>

int main() {
    std::clock_t startTime = std::clock();
    std::string phone;
    std::cin >> phone;

    std::string mapping = "222333444555666777788899";
    for (char &c : phone) {
        if (c == '-') continue;
        c = toupper(c);
        c = mapping[c - 'A' - 19];
    }

    std::cout << phone << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}