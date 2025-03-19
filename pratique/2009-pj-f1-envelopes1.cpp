#include <ctime>
#include <iostream>
#include <vector>

int main() {
    std::clock_t startTime = std::clock();
    int N;
    std::cin >> N;

    std::vector<int> rotulos(N);
    for (int i = 0; i < N; i++) {
        std::cin >> rotulos[i];
    }

    int envelopes = INT_MAX;
    for (int i = 0; i < N; i++) {
        envelopes = std::min(envelopes, rotulos[i]);
    }

    std::cout << envelopes << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}