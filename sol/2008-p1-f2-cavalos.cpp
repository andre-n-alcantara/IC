#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int solve(int M, int N) {
    if (M == 1) return N;
    if (N == 1) return M;
    if (M == 2) return N / 2 * 2;
    if (N == 2) return M / 2 * 2;
    return (M * N + 1) / 2;
}

int main() {
    std::clock_t startTime = std::clock();
    int M, N;
    cin >> M >> N;
    cout << solve(M, N) << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}