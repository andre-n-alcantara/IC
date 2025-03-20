#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
unordered_map<int, int> depth;

int dfs(int node, int parent, int d) {
    visited[node] = true;
    depth[node] = d;
    int max_depth = d;
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            if (!visited[neighbor]) {
                max_depth = max(max_depth, dfs(neighbor, node, d + 1));
            } else if (depth[neighbor] < d) {
                max_depth = max(max_depth, depth[neighbor]);
            }
        }
    }
    return max_depth;
}

int main() {
    int N;
    cin >> N;
    adj.resize(N + 1);
    visited.resize(N + 1, false);
    depth.resize(N + 1, 0);

    for (int i = 0; i < N - 1; i++) {
        int X, Y;
        cin >> X >> Y;
        adj[X].push_back(Y);
        adj[Y].push_back(X);
    }

    int max_cycle_len = 0;
    int max_cycle_count = 0;

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            int cycle_len = dfs(i, -1, 0);
            if (cycle_len > max_cycle_len) {
                max_cycle_len = cycle_len;
                max_cycle_count = 1;
            } else if (cycle_len == max_cycle_len) {
                max_cycle_count++;
            }
        }
    }

    cout << max_cycle_len << endl;
    cout << max_cycle_count << endl;

    return 0;
}