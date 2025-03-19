#include <ctime>
#include <iostream>

using namespace std;

long long countPositions(int n, int t) {
    if (t == 0) {
        return n;
    } else if (t == 1) {
        return n * (n - 1);
    } else {
        return (n * (n - 1) * (n - 2)) / 2;
    }
}

int main() {
    std::clock_t startTime = std::clock();
    int n, t;
    cin >> n >> t;
    cout << countPositions(n, t) << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}