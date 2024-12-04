
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;

    vector<bool> infected(N + 1, false);
    vector<int> parent(N + 1, -1);

    for (int i = 0; i < C; i++) {
        int P, I;
        cin >> P >> I;
        infected[P] = true;
        for (int j = 0; j < I; j++) {
            int Xi;
            cin >> Xi;
            infected[Xi] = true;
            parent[Xi] = P;
        }
    }

    unordered_set<int> zeros;
    for (int i = 1; i <= N; i++) {
        if (!infected[i]) continue;
        if (parent[i] == -1) zeros.insert(i);
    }

    for (int zero : zeros) {
        cout << zero << endl;
    }

    return 0;
}
