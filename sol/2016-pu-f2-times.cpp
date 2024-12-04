#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[105];
int color[105];

bool bfs(int v) {
    queue<int> q;
    q.push(v);
    color[v] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int w : graph[u]) {
            if (color[w] == 0) {
                color[w] = 3 - color[u];
                q.push(w);
            } else if (color[w] == color[u]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int M;
        cin >> M;
        while (M--) {
            int X;
            cin >> X;
            graph[i].push_back(X);
            graph[X].push_back(i);
        }
    }
    for (int i = 2; i <= N; i++) {
        if (!bfs(i)) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    vector<int> time1, time2;
    for (int i = 1; i <= N; i++) {
        if (color[i] == 1) time1.push_back(i);
        else time2.push_back(i);
    }
    for (int v : time1) cout << v << " ";
    cout << endl;
    for (int v : time2) cout << v << " ";
    cout << endl;
    return 0;
}