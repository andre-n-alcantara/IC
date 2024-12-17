#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int N;
    std::cin >> N;

    int mines[N];
    for (int i = 0; i < N; i++) {
        std::cin >> mines[i];
    }

    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int j = i - 1; j <= i + 1; j++) {
            if (j >= 0 && j < N && mines[j] == 1) {
                count++;
            }
        }
        if (mines[i] == 0) {
            count--;
        }
        std::cout << count << std::endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}