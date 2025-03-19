#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N, D;
    cin >> N >> D;
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    vector<int> prefixSum(N + 1, 0);
    for (int i = 0; i < N; i++) {
        prefixSum[i + 1] = prefixSum[i] + C[i];
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (prefixSum[j + 1] - prefixSum[i] == D) {
                count++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 2; j < N; j++) {
            if (C[i] + C[j] + prefixSum[N] - prefixSum[j + 1] == D) {
                count++;
            }
        }
    }

    cout << count << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}