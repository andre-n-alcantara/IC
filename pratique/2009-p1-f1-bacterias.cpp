#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int N;
    std::cin >> N;

    long long max_bacteria = 0;
    int best_type = 0;

    for (int i = 0; i < N; i++) {
        int D, C;
        std::cin >> D >> C;

        long long bacteria = 1;
        for (int j = 0; j < C; j++) {
            bacteria *= D;
        }

        if (bacteria > max_bacteria) {
            max_bacteria = bacteria;
            best_type = i;
        }
    }

    std::cout << best_type << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}