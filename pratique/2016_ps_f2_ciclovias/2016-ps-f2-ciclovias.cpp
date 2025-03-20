#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 105;

vector<int> adj[MAX_N];
int dp[MAX_N][MAX_N];

int dfs(int u, int par, int len) {
    if (dp[u][len] != -1) return dp[u][len];
    int ans = 0;
    for (int v : adj[u]) {
        if (v != par) {
            ans = max(ans, dfs(v, u, len + 1));
        }
    }
    return dp[u][len] = ans;
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    memset(dp, -1, sizeof(dp));

    vector<int> ans(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        ans[i] = dfs(i, 0, 0);
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}