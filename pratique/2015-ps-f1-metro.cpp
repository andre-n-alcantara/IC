#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[20001];
bool visited[20001];

void dfs(int node, int &count) {
    visited[node] = true;
    count++;
    for (int i = 0; i < graph[node].size(); i++) {
        if (!visited[graph[node][i]]) {
            dfs(graph[node][i], count);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int P, Q;
        cin >> P >> Q;
        graph[P].push_back(Q);
        graph[Q].push_back(P);
    }
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i, count);
            break;
        }
    }
    cout << count << endl;
    return 0;
}