#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[10001];
int dist[10001];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 0; i < graph[v].size(); i++) {
            int to = graph[v][i];
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 1; i < n; i++) {
        int p, q;
        cin >> p >> q;
        graph[p].push_back(q);
        graph[q].push_back(p);
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = -1;
    }

    bfs(a);

    cout << dist[b] << endl;

    return 0;
}