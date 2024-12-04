#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> graph[10001];
int distance[10001];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    distance[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > distance[u]) continue;

        for (auto edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                pq.push({distance[v], v});
            }
        }
    }
}

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    for (int i = 1; i < N; i++) {
        int P, Q, D;
        cin >> P >> Q >> D;
        graph[P].push_back({Q, D});
        graph[Q].push_back({P, D});
    }

    for (int i = 1; i <= N; i++) {
        distance[i] = 1e9;
    }

    dijkstra(A);

    cout << distance[B] << endl;

    return 0;
}