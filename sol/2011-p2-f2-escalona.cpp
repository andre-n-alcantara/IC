#include <ctime>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[50001];
vector<int> indegree(50001);
queue<int> q;
vector<int> order;

void toposort(int n) {
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
}

int main() {
    std::clock_t startTime = std::clock();
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    toposort(n);

    if (order.size() != n) {
        cout << "*\n";
    } else {
        for (int i = 0; i < n; i++) {
            cout << order[i] << "\n";
        }
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}