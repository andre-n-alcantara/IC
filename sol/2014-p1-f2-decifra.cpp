#include <ctime>
#include <iostream>
#include <string>

int main() {
    std::clock_t startTime = std::clock();
    std::string permutation, encryptedText;
    std::getline(std::cin, permutation);
    std::getline(std::cin, encryptedText);

    for (char& c : encryptedText) {
        c = permutation[c - 'a'];
    }

    std::cout << encryptedText << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}