#include <ctime>
#include <iostream>
using namespace std;

int countDivisors(int n) {
    int count = 1;
    for (int i = 2; i * i <= n; i++) {
        int power = 0;
        while (n % i == 0) {
            n /= i;
            power++;
        }
        if (power > 0) {
            count *= (power + 1);
        }
    }
    if (n > 1) {
        count *= 2;
    }
    return count;
}

int main() {
    std::clock_t startTime = std::clock();
    int n;
    cin >> n;
    cout << countDivisors(n) << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}