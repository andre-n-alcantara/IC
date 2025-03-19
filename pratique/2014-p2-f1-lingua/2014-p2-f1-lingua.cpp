#include <ctime>
#include <iostream>
#include <string>

int main() {
    std::clock_t startTime = std::clock();
    std::string input;
    std::getline(std::cin, input);

    std::string output;
    for (char c : input) {
        if (c == 'p' && input[input.find(c) + 1] != ' ') {
            continue;
        }
        output += c;
    }

    std::cout << output << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}