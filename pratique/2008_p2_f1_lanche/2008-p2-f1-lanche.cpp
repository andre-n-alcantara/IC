#include <ctime>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 0x3f3f3f3f

vector<vector<pair<int, int>>> grafo;
vector<int> distancia;

int dijkstra(int inicio) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, inicio});
    distancia[inicio] = 0;

    while (!pq.empty()) {
        int atual = pq.top().second;
        int custo_atual = pq.top().first;
        pq.pop();

        if (custo_atual > distancia[atual]) continue;

        for (auto &edge : grafo[atual]) {
            int proximo = edge.first;
            int peso = edge.second;

            if (distancia[proximo] > distancia[atual] + peso) {
                distancia[proximo] = distancia[atual] + peso;
                pq.push({distancia[proximo], proximo});
            }
        }
    }

    int max_dist = 0;
    for (int i = 1; i < distancia.size(); i++) {
        max_dist = max(max_dist, distancia[i]);
    }

    return max_dist;
}

int main() {
    int S, C;
    cin >> S >> C;

    grafo.resize(S + 1);
    distancia.resize(S + 1, INF);

    for (int i = 0; i < C; i++) {
        int A, B, D;
        cin >> A >> B >> D;
        grafo[A].push_back({B, D});
        grafo[B].push_back({A, D});
    }

    int min_dist = INF;
    for (int i = 1; i <= S; i++) {
        distancia.assign(S + 1, INF);
        min_dist = min(min_dist, dijkstra(i));
    }

    cout << min_dist << endl;

    
return 0;
}