#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int N, C, S;
    std::cin >> N >> C >> S;

    int currentStation = 1;
    int count = 0;

    for (int i = 0; i < C; i++) {
        int command;
        std::cin >> command;

        if (command == 1) {
            currentStation = (currentStation % N) + 1;
        } else {
            currentStation = (currentStation - 2 + N) % N + 1;
        }

        if (currentStation == S) {
            count++;
        }
    }

    std::cout << count << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}