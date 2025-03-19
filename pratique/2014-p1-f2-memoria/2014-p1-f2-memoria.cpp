#include <ctime>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 50001;

vector<int> graph[MAX_N];
int dist[MAX_N];

void bfs(int start, int N) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : graph[v]) {
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> cards(N);
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
    }
    for (int i = 0; i < N-1; i++) {
        int A, B;
        cin >> A >> B;
        graph[A-1].push_back(B-1);
        graph[B-1].push_back(A-1);
    }
    int sum = 0;
    for (int i = 0; i < N/2; i++) {
        memset(dist, -1, sizeof(dist));
        bfs(cards.index_of(i+1)-1, N);
        for (int j = i+1; j < N; j++) {
            if (cards[j] == i+1) {
                sum += dist[j];
                break;
            }
        }
    }
    cout << sum << endl;
    
return 0;
}