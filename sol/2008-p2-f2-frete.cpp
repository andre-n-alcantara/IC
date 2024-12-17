#include <ctime>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to, cost;
};

vector<vector<Edge>> graph;
vector<int> distances;

int dijkstra(int start) {
    distances.assign(graph.size(), INF);
    distances[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int curr = pq.top().second;
        int curr_dist = pq.top().first;
        pq.pop();

        if (curr_dist > distances[curr]) continue;

        for (const Edge& e : graph[curr]) {
            int to = e.to;
            int cost = e.cost;
            if (distances[to] > distances[curr] + cost) {
                distances[to] = distances[curr] + cost;
                pq.push({distances[to], to});
            }
        }
    }

    int min_dist = INF;
    for (int i = 0; i < graph.size(); ++i) {
        if (i != start) {
            min_dist = min(min_dist, distances[i]);
        }
    }

    return min_dist;
}

int main() {
    std::clock_t startTime = std::clock();
    int N, M;
    cin >> N >> M;

    graph.resize(N);
    for (int i = 0; i < M; ++i) {
        int P, Q, U;
        cin >> P >> Q >> U;
        graph[P].push_back({Q, U});
        graph[Q].push_back({P, U});
    }

    int min_cost = INF;
    for (int i = 0; i < N; ++i) {
        min_cost = min(min_cost, dijkstra(i));
    }

    cout << min_cost << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}