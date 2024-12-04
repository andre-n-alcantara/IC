
#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[10005];
bool visited[10005];

void dfs(int node) {
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        if (!visited[graph[node][i]]) {
            dfs(graph[node][i]);
        }
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
    }
    dfs(1);
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            cout << "N" << endl;
            return 0;
        }
    }
    cout << "S" << endl;
    return 0;
}
