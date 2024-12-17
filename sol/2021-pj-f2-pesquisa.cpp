#include <ctime>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::clock_t startTime = std::clock();
    int N;
    std::cin >> N;

    std::vector<std::string> vantajosos;

    for (int i = 0; i < N; i++) {
        std::string E;
        double A, G;
        std::cin >> E >> A >> G;

        if (A <= 0.7 * G) {
            vantajosos.push_back(E);
        }
    }

    if (vantajosos.empty()) {
        std::cout << "*\n";
    } else {
        for (const auto& estado : vantajosos) {
            std::cout << estado << "\n";
        }
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}