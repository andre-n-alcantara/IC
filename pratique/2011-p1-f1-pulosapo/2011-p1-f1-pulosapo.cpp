#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N, M;
    cin >> N >> M;

    vector<bool> canHaveFrog(N + 1, false);

    for (int i = 0; i < M; i++) {
        int P, D;
        cin >> P >> D;

        for (int j = P; j <= N; j += D) {
            canHaveFrog[j] = true;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << (canHaveFrog[i] ? 1 : 0) << endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}