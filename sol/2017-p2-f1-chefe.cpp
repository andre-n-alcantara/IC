
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[501];
vector<int> age(501);
int parent[501];

void bfs(int node) {
    queue<int> q;
    q.push(node);
    parent[node] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (parent[v] == 0) {
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

int find_youngest_manager(int node) {
    if (parent[node] == -1) return -1;
    queue<int> q;
    q.push(node);
    int youngest = age[node];
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (age[v] < youngest) youngest = age[v];
            q.push(v);
        }
    }
    return youngest;
}

int main() {
    int N, M, I;
    cin >> N >> M >> I;
    for (int i = 1; i <= N; i++) {
        cin >> age[i];
    }
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    char command;
    for (int i = 0; i < I; i++) {
        cin >> command;
        if (command == 'T') {
            int A, B;
            cin >> A >> B;
            swap(graph[A], graph[B]);
        } else {
            int E;
            cin >> E;
            bfs(E);
            int youngest = find_youngest_manager(E);
            if (youngest == -1) cout << "*" << endl;
            else cout << youngest << endl;
        }
    }
    return 0;
}
