#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> graph;
unordered_set<int> circularStations;

void dfs(int station, int parent) {
    circularStations.insert(station);
    for (int neighbor : graph[station]) {
        if (neighbor != parent) {
            dfs(neighbor, station);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    graph.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int P, Q;
        cin >> P >> Q;
        graph[P].push_back(Q);
        graph[Q].push_back(P);
    }

    dfs(1, 0);

    cout << circularStations.size() << endl;

    return 0;
}