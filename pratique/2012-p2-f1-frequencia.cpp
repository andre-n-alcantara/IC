#include <ctime>
#include <iostream>
#include <set>

int main() {
    std::clock_t startTime = std::clock();
    int N;
    std::cin >> N;

    std::set<int> alunos;

    for (int i = 0; i < N; i++) {
        int Vi;
        std::cin >> Vi;
        alunos.insert(Vi);
    }

    std::cout << alunos.size() << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}