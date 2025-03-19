#include <ctime>
#include <iostream>
using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int n, m;
    cin >> n >> m;
    cout << (n % (m + 1) == 0 ? "Carlos" : "Paula") << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}