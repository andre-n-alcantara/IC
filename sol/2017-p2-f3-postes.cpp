#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int N;
    std::cin >> N;

    int substituir = 0, consertar = 0;
    for (int i = 0; i < N; i++) {
        int tamanho;
        std::cin >> tamanho;
        if (tamanho < 50) {
            substituir++;
        } else if (tamanho < 85) {
            consertar++;
        }
    }

    std::cout << substituir << " " << consertar << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}