#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<bool> alive(N + 1, true);

    for (int i = 0; i < M; i++) {
        int Ti;
        cin >> Ti;
        for (int j = Ti; j <= N; j += Ti) {
            alive[j] = false;
        }
    }

    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (alive[i]) {
            cout << i << endl;
            count++;
            if (count == 10000) break;
        }
    }

    return 0;
}