#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graphC, graphQ;
vector<bool> visitedC, visitedQ;

int bfsC(int start, int N) {
    queue<int> q;
    q.push(start);
    visitedC[start] = true;
    int maxDist = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : graphC[node]) {
            if (!visitedC[neighbor]) {
                visitedC[neighbor] = true;
                q.push(neighbor);
                maxDist = max(maxDist, abs(node - neighbor));
            }
        }
    }
    return maxDist;
}

int bfsQ(int start, int M) {
    queue<int> q;
    q.push(start);
    visitedQ[start] = true;
    int maxDist = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : graphQ[node]) {
            if (!visitedQ[neighbor]) {
                visitedQ[neighbor] = true;
                q.push(neighbor);
                maxDist = max(maxDist, abs(node - neighbor));
            }
        }
    }
    return maxDist;
}

int main() {
    int N, M;
    cin >> N >> M;
    graphC.resize(N + 1);
    graphQ.resize(M + 1);
    visitedC.resize(N + 1, false);
    visitedQ.resize(M + 1, false);

    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        graphC[A].push_back(B);
        graphC[B].push_back(A);
    }

    for (int i = 0; i < M - 1; i++) {
        int X, Y;
        cin >> X >> Y;
        graphQ[X].push_back(Y);
        graphQ[Y].push_back(X);
    }

    int minDiameter = INT_MAX;
    int stationC, stationQ;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int diameter = max(bfsC(i, N), bfsQ(j, M)) + 1;
            if (diameter < minDiameter) {
                minDiameter = diameter;
                stationC = i;
                stationQ = j;
            }
        }
    }

    cout << stationC << " " << stationQ << endl;

    return 0;
}