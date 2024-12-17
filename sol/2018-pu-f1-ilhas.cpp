#include <ctime>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int to;
    int weight;
};

vector<vector<Edge>> graph;
vector<bool> visited;
vector<int> dist;

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (Edge e : graph[u]) {
            if (dist[e.to] > dist[u] + e.weight) {
                dist[e.to] = dist[u] + e.weight;
                pq.push({dist[e.to], e.to});
            }
        }
    }
}

int main() {
    std::clock_t startTime = std::clock();
    int N, M;
    cin >> N >> M;

    graph.resize(N + 1);
    visited.resize(N + 1, false);
    dist.resize(N + 1, INT_MAX);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int S;
    cin >> S;

    dijkstra(S);

    int min_dist = INT_MAX;
    int max_dist = 0;

    for (int i = 1; i <= N; i++) {
        if (i != S) {
            if (dist[i] < min_dist) min_dist = dist[i];
            if (dist[i] > max_dist) max_dist = dist[i];
        }
    }

    cout << max_dist - min_dist << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}