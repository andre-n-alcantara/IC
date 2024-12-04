#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 0; i < graph[v].size(); i++) {
            if (!visited[graph[v][i]]) {
                q.push(graph[v][i]);
                visited[graph[v][i]] = true;
            }
        }
    }
}

int main() {
    int E, I, V;
    cin >> E >> I >> V;

    graph.resize(E + 1);
    visited.resize(E + 1, false);

    for (int i = 0; i < I; i++) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
    }

    for (int i = 0; i < V; i++) {
        int v;
        cin >> v;
        if (!visited[v]) {
            bfs(v);
        }
    }

    for (int i = 1; i <= E; i++) {
        if (visited[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}