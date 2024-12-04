#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<bool> canHaveFrog(N + 1, false);

    for (int i = 0; i < M; i++) {
        int P, D;
        cin >> P >> D;

        for (int j = P; j <= N; j += D) {
            canHaveFrog[j] = true;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << (canHaveFrog[i] ? 1 : 0) << endl;
    }

    return 0;
}