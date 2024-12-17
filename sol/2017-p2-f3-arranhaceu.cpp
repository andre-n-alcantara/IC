#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N, Q;
    cin >> N >> Q;
    vector<int> pessoas(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> pessoas[i];
    }
    vector<int> prefixSum(N + 1);
    for (int i = 1; i <= N; i++) {
        prefixSum[i] = prefixSum[i - 1] + pessoas[i];
    }
    for (int i = 0; i < Q; i++) {
        int tipo, K, P;
        cin >> tipo >> K;
        if (tipo == 0) {
            cin >> P;
            pessoas[K] = P;
        } else {
            cout << prefixSum[K] << endl;
        }
    }
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}