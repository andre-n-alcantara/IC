#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N, M, C;
    cin >> N >> M >> C;

    vector<pair<int, int>> friends(N);
    for (int i = 0; i < N; i++) {
        cin >> friends[i].first >> friends[i].second;
    }

    int currentSong = C;
    int swaps = 0;
    while (true) {
        bool satisfied = true;
        for (int i = 0; i < N; i++) {
            if (friends[i].second == currentSong) {
                currentSong = friends[i].first;
                swaps++;
                satisfied = false;
                break;
            }
        }
        if (satisfied) break;
    }

    if (swaps == 0) swaps = -1; // no swaps or infinite loop
    cout << swaps << endl;

    return 0;
}