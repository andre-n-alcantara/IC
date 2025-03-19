#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> cars(N);
    for (int i = 0; i < N; i++) {
        int total_time = 0;
        for (int j = 0; j < M; j++) {
            int time;
            cin >> time;
            total_time += time;
        }
        cars[i] = make_pair(total_time, i + 1);
    }

    sort(cars.begin(), cars.end());

    for (int i = 0; i < 3; i++) {
        cout << cars[i].second << endl;
    }

    return 0;
}