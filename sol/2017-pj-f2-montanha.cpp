#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int N;
    std::cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    bool multi_pico = false;
    for (int i = 1; i < N - 1; i++) {
        if (A[i-1] > A[i] && A[i] < A[i+1]) {
            multi_pico = true;
            break;
        }
    }
    if (multi_pico) {
        std::cout << "S\n";
    } else {
        std::cout << "N\n";
    }
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}