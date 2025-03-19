#include <ctime>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 500;
const int INF = 1e9;

vector<vector<pair<int, int>>> graph(MAX);
vector<bool> visited(MAX);
int dist[MAX];

int bfs(int start, int end, int n) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto edge : graph[u]) {
            int v = edge.first;
            int time = edge.second;

            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;

                if (v == end) {
                    return dist[v];
                }

                q.push(v);
            }
        }
    }

    return -1;
}

int main() {
    int n, e, s, m;
    cin >> n >> e >> s >> m;

    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;

        graph[a].push_back({b, t});
        graph[b].push_back({a, 1 - t});
    }

    int ans = bfs(e, s, n);

    if (ans == -1) {
        cout << "*" << endl;
    } else {
        cout << ans << endl;
    }

    
return 0;
}