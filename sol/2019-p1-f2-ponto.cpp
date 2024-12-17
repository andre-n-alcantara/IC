#include <ctime>
#include <bits/stdc++.h>
using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int n;
    cin >> n;
    cout << (1LL * (1 << (2 * n)) - (1 << n) + 1) << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}