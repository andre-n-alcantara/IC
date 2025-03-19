#include <ctime>
#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::clock_t startTime = std::clock();
    std::string input;
    std::getline(std::cin, input);

    bool isPangram = true;
    bool alphabet[26] = {false};

    for (char c : input) {
        if (std::isalpha(c)) {
            char lower = std::tolower(c);
            if (lower >= 'a' && lower <= 'z') {
                alphabet[lower - 'a'] = true;
            }
        }
    }

    for (bool b : alphabet) {
        if (!b) {
            isPangram = false;
            break;
        }
    }

    if (isPangram) {
        std::cout << "S" << std::endl;
    } else {
        std::cout << "N" << std::endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}