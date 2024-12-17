#include <ctime>
#include <iostream>
using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    long long L, N;
    cin >> L >> N;

    long long sum = 0;
    long long i = 1;
    while(L > 0 && N > 0) {
        long long side = min(L, i);
        sum += side * side;
        L -= side;
        i++;
        N--;
    }

    cout << sum << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}