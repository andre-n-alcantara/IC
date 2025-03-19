#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N, F;
    cin >> N >> F;
    vector<int> capsules(N);
    for (int i = 0; i < N; i++) {
        cin >> capsules[i];
    }
    int days = 0;
    int coins = 0;
    while (coins < F) {
        days++;
        for (int i = 0; i < N; i++) {
            if (days % capsules[i] == 0) {
                coins++;
            }
        }
    }
    cout << days << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}