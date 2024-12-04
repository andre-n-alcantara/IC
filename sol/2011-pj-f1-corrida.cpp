
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
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

    return 0;
}
