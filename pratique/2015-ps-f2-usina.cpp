#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<vector<pair<int, int>>> graph;
vector<bool> hasPerson;
vector<int> dist;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int d = edge.second;

            if (dist[v] > dist[u] + d) {
                dist[v] = dist[u] + d;
                q.push(v);
            }
        }
    }
}

int main() {
    int N, M, C, K;
    cin >> N >> M >> C >> K;

    graph.resize(N + 1);
    hasPerson.resize(N + 1, false);
    dist.resize(N + 1, INF);

    for (int i = 0; i < C; i++) {
        int p;
        cin >> p;
        hasPerson[p] = true;
    }

    for (int i = 0; i < M; i++) {
        int A, B, D;
        cin >> A >> B >> D;
        graph[A].push_back({B, D});
    }

    if (hasPerson[1]) {
        bfs(1);
    } else {
        for (int i = 1; i <= N; i++) {
            if (hasPerson[i]) {
                bfs(i);
                break;
            }
        }
    }

    if (dist[N] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[N] << endl;
    }

    return 0;
}