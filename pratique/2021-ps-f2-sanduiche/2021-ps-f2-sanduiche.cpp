#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int MAX_N = 20;

vector<vector<int>> graph(MAX_N);
bitset<MAX_N> dp[(1 << MAX_N)];

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        graph[X - 1].push_back(Y - 1);
        graph[Y - 1].push_back(X - 1);
    }

    dp[0].set();
    for (int mask = 0; mask < (1 << N); mask++) {
        for (int i = 0; i < N; i++) {
            if (!(mask & (1 << i))) continue;
            for (int j : graph[i]) {
                if (mask & (1 << j)) continue;
                dp[mask | (1 << j)] |= dp[mask];
            }
        }
    }

    int ans = 0;
    for (int mask = 1; mask < (1 << N); mask++) {
        if (dp[mask].count() > 0) ans++;
    }

    cout << ans << endl;

    return 0;
}