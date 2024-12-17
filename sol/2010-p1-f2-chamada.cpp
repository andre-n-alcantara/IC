#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::clock_t startTime = std::clock();
    int N, K;
    std::cin >> N >> K;

    std::vector<std::string> alunos(N);
    for (int i = 0; i < N; i++) {
        std::cin >> alunos[i];
    }

    std::sort(alunos.begin(), alunos.end());

    std::cout << alunos[K - 1] << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}