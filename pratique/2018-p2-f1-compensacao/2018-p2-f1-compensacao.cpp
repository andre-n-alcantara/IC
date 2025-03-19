#include <ctime>
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<pair<int, int>>> graph(N + 1);
    vector<int> inDegree(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int X, V, Y;
        cin >> X >> V >> Y;
        graph[X].push_back({Y, V});
        inDegree[Y]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    string ans = "N";
    int total = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        total += node;

        for (auto& edge : graph[node]) {
            int neighbor = edge.first;
            int value = edge.second;
            inDegree[neighbor] -= value;

            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (total < M) {
        ans = "S";
    }

    cout << ans << endl;
    if (ans == "S") {
        cout << total << endl;
    } else {
        cout << "" << endl;
    }

    
return 0;
}