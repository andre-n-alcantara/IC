#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N, K;
    cin >> N >> K;

    vector<int> distances(N);
    for (int i = 0; i < N; i++) {
        cin >> distances[i];
    }

    sort(distances.begin(), distances.end());

    int minDistance = distances[N - 1] - distances[0];
    for (int i = 0; i <= K; i++) {
        minDistance = min(minDistance, distances[N - i - 1] - distances[i]);
    }

    cout << minDistance << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}