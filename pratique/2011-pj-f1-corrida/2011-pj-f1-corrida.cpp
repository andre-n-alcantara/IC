#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N, M;
    cin >> N >> M;

    vector<pair<long long, int>> times(N);

    for (int i = 0; i < N; i++) {
        long long total_time = 0;
        for (int j = 0; j < M; j++) {
            int time;
            cin >> time;
            total_time += time;
        }
        times[i] = make_pair(total_time, i + 1);
    }

    sort(times.begin(), times.end());

    for (int i = 0; i < 3; i++) {
        cout << times[i].second << endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}