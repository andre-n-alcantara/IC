#include <ctime>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to, time;
};

vector<Edge> graph[1005];
int dist[1005];

void dijkstra(int start) {
    fill(dist, dist + 1005, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int v = pq.top().second;
        int d_v = pq.top().first;
        pq.pop();
        if (d_v != dist[v]) continue;
        for (Edge e : graph[v]) {
            int to = e.to;
            int time = e.time;
            if (dist[to] > dist[v] + time) {
                dist[to] = dist[v] + time;
                pq.push({dist[to], to});
            }
        }
    }
}

int main() {
    std::clock_t startTime = std::clock();
    int S, C;
    cin >> S >> C;
    for (int i = 0; i < C; i++) {
        int I, F, T;
        cin >> I >> F >> T;
        graph[I].push_back({F, T});
    }
    int ans = INF;
    for (int i = 1; i <= S; i++) {
        dijkstra(i);
        for (int j = 1; j <= S; j++) {
            if (i == j) continue;
            ans = min(ans, dist[j] + dist[i]);
        }
    }
    cout << ans << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}