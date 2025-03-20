#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> graph[105];
vector<int> team1, team2;
bool visited[105];

void dfs(int node, int team) {
    visited[node] = true;
    if (team == 1) team1.push_back(node);
    else team2.push_back(node);
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) dfs(neighbor, 3 - team);
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int M;
        cin >> M;
        for (int j = 0; j < M; j++) {
            int X;
            cin >> X;
            graph[i].push_back(X);
            graph[X].push_back(i);
        }
    }
    dfs(1, 1);
    sort(team1.begin(), team1.end());
    sort(team2.begin(), team2.end());
    for (int node : team1) cout << node << " ";
    cout << endl;
    for (int node : team2) cout << node << " ";
    cout << endl;
    return 0;
}