#include <ctime>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int bfs(vector<vector<int>> &graph, int O, int D) {
    queue<pair<int, int>> q;
    unordered_map<int, bool> visited;
    q.push({O, 0});
    visited[O] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (node == D) return dist;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push({neighbor, dist + 1});
                visited[neighbor] = true;
            }
        }
    }

    return -1; // não há caminho entre O e D
}

int main() {
    std::clock_t startTime = std::clock();
    int T, L, O, D;
    cin >> T >> L >> O >> D;

    vector<vector<int>> graph(T + 1);

    for (int i = 1; i <= L; i++) {
        int C;
        cin >> C;
        for (int j = 0; j < C; j++) {
            int terminal;
            cin >> terminal;
            graph[terminal].push_back(i);
        }
    }

    int min_lines = bfs(graph, O, D);
    cout << min_lines << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}