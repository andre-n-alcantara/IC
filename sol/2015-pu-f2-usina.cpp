#include <ctime>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N, M, C, K;
    cin >> N >> M >> C >> K;

    vector<int> people(C);
    for (int i = 0; i < C; i++) {
        cin >> people[i];
    }

    vector<vector<pair<int, int>>> slides(N + 1);
    for (int i = 0; i < M; i++) {
        int A, B, D;
        cin >> A >> B >> D;
        slides[A].push_back({B, D});
    }

    vector<int> dist(N + 1, numeric_limits<int>::max());
    dist[1] = 0;

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto &slide : slides[cur]) {
            int next = slide.first;
            int d = slide.second;

            if (dist[next] > dist[cur] + d) {
                dist[next] = dist[cur] + d;
                q.push(next);
            }
        }
    }

    int ans = -1;
    for (int i = 0; i < C; i++) {
        if (dist[people[i]] != numeric_limits<int>::max() && dist[people[i]] / K <= dist[N]) {
            if (ans == -1 || dist[people[i]] / K < ans) {
                ans = dist[people[i]] / K;
            }
        }
    }

    cout << ans << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}