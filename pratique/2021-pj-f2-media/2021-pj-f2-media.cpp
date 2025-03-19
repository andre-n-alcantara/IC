#include <ctime>
#include <iostream>
using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    long long A, B;
    cin >> A >> B;
    long long minC = (A + B) / 2 - A;
    if ((A + B + minC) % 3 != 0) minC--;
    cout << minC << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}