#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> shells(N);
    for (int i = 0; i < N; i++) {
        cin >> shells[i];
    }

    for (int i = 0; i < M; i++) {
        int idx;
        cin >> idx;
        idx--; // convert to 0-based index

        int count = shells[idx];
        shells[idx]--;

        for (int j = idx - count; j <= idx + count; j++) {
            if (j >= 0 && j < N) {
                shells[j]--;
            }
        }
    }

    int total = 0;
    for (int i = 0; i < N; i++) {
        total += max(0, shells[i]);
    }

    cout << total << endl;

    return 0;
}