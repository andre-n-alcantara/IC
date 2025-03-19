#include <ctime>
#include <iostream>

int gcd(long long int a, long long int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    std::clock_t startTime = std::clock();
    long long int N, M;
    std::cin >> N >> M;

    for (long long int X = M; X >= 1; X--) {
        if (gcd(X, N) == 1) {
            std::cout << X << std::endl;
            
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
        }
    }

    return 0;
}