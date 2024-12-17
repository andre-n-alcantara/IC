#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N, M;
    cin >> N >> M;

    vector<int> conchas(N);
    for (int i = 0; i < N; i++) {
        cin >> conchas[i];
    }

    vector<int> indices(M);
    for (int i = 0; i < M; i++) {
        cin >> indices[i];
    }

    for (int i = 0; i < M; i++) {
        int idx = indices[i] - 1;
        int count = conchas[idx];
        conchas[idx]--;
        for (int j = max(0, idx - count); j <= min(N - 1, idx + count); j++) {
            conchas[j]--;
            if (conchas[j] < 0) conchas[j] = 0;
        }
    }

    int total = 0;
    for (int concha : conchas) {
        total += concha;
    }

    cout << total << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}