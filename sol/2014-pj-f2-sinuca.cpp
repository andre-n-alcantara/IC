#include <ctime>
#include <iostream>
#include <vector>

int main() {
    std::clock_t startTime = std::clock();
    int N;
    std::cin >> N;

    std::vector<int> row(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> row[i];
    }

    for (int i = N - 1; i > 0; --i) {
        std::vector<int> newRow(i);
        for (int j = 0; j < i; ++j) {
            newRow[j] = (row[j] == row[j + 1]) ? row[j] : -row[j];
        }
        row = newRow;
    }

    std::cout << (row[0] == 1 ? "preta" : "branca") << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}