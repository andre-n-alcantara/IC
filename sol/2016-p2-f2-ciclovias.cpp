#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> degree;
vector<int> dp;

void dfs(int node, int parent) {
    int mx = 0, mn = INT_MAX;
    for (int child : graph[node]) {
        if (child == parent) continue;
        dfs(child, node);
        mx = max(mx, dp[child]);
        mn = min(mn, dp[child]);
    }
    dp[node] = max(dp[node], mx + mn + 1);
}

int main() {
    int N, M;
    cin >> N >> M;
    graph.resize(N + 1);
    degree.resize(N + 1, 0);
    dp.resize(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
        degree[A]++;
        degree[B]++;
    }
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (degree[i] == 1) q.push(i);
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        dfs(node, 0);
        for (int child : graph[node]) {
            degree[child]--;
            if (degree[child] == 1) q.push(child);
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
    return 0;
}