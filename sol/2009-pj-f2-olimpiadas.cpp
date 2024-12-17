#include <ctime>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N, M;
    cin >> N >> M;

    vector<int> medals(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int O, P, B;
        cin >> O >> P >> B;
        medals[O]++;
        medals[P]++;
        medals[B]++;
    }

    vector<pair<int, int>> ranking(N);
    for (int i = 1; i <= N; i++) {
        ranking[i - 1] = make_pair(medals[i], i);
    }

    sort(ranking.rbegin(), ranking.rend());

    for (int i = 0; i < N; i++) {
        cout << ranking[i].second << " ";
    }
    cout << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}