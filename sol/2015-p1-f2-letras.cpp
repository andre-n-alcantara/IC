#include <ctime>
#include <iostream>
#include <string>

int main() {
    std::clock_t startTime = std::clock();
    std::string s;
    std::cin >> s;

    int max_length = 0;
    int current_length = 1;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] >= s[i - 1]) {
            current_length++;
        } else {
            max_length = std::max(max_length, current_length);
            current_length = 1;
        }
    }

    max_length = std::max(max_length, current_length);

    std::cout << max_length << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}