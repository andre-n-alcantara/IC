#include <ctime>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int A, L, N;
    cin >> A >> L >> N;

    int bestFrame = -1;
    int minDiff = INT_MAX;

    for (int i = 1; i <= N; i++) {
        int Xi, Yi;
        cin >> Xi >> Yi;

        int maxDim = max(Xi, Yi);
        int minDim = min(Xi, Yi);

        if (maxDim >= A && minDim >= L) {
            int diff = maxDim * minDim - A * L;
            if (diff < minDiff) {
                minDiff = diff;
                bestFrame = i;
            }
        }

        if (maxDim >= L && minDim >= A) {
            int diff = maxDim * minDim - A * L;
            if (diff < minDiff) {
                minDiff = diff;
                bestFrame = i;
            }
        }
    }

    cout << bestFrame << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}