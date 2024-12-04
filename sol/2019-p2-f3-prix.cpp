
#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[200010];
int low[200010], disc[200010], timer;
bool visited[200010];

void dfs(int node, int parent) {
    visited[node] = true;
    low[node] = disc[node] = timer++;
    int children = 0;

    for (int child : graph[node]) {
        if (!visited[child]) {
            children++;
            dfs(child, node);
            low[node] = min(low[node], low[child]);
            if ((parent != -1 && low[child] >= disc[node]) ||
                (parent == -1 && children > 1)) {
                cout << parent + 1 << endl;
                exit(0);
            }
        } else if (child != parent) {
            low[node] = min(low[node], disc[child]);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, l, r;
        cin >> u >> l >> r;
        for (int j = l; j <= r; j++) {
            graph[u].push_back(j);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }

    cout << -1 << endl;
    return 0;
}
