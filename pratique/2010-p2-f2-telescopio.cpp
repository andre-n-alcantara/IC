#include <ctime>
#include <iostream>
using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int A, N;
    cin >> A >> N;

    int count = 0;
    for (int i = 0; i < N; i++) {
        int F;
        cin >> F;
        if (F * A >= 40000000) count++;
    }

    cout << count << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}