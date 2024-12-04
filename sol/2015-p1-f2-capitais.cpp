#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[100005];
int dist[100005];

int bfs(int start, int end) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist[end];
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int min_dist = INT_MAX;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            fill(dist, dist + N + 1, -1);
            int d = bfs(i, j);
            if (d != -1) {
                min_dist = min(min_dist, d);
            }
        }
    }

    cout << min_dist << endl;

    return 0;
}