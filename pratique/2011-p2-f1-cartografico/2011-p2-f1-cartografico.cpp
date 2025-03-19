#include <ctime>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[100000];
int dist[100000];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    fill(dist, dist + N + 1, -1);
    bfs(1);
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, dist[i]);
    }
    cout << ans << endl;
    
return 0;
}