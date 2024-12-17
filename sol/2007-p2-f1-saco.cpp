#include <ctime>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 31;
const int MAX_T = 101;

int n, t;
vector<vector<int> > graph(MAX_N);
vector<int> cost(MAX_N);
vector<char> group(MAX_N);
vector<vector<bool> > dp(MAX_T, vector<bool>(MAX_T, false));

int solve() {
    dp[0][0] = true;
    queue<pair<int, int> > q;
    q.push({0, 0});
    int ans = INT_MAX;

    while (!q.empty()) {
        int a = q.front().first, b = q.front().second;
        q.pop();

        if (a >= b) ans = min(ans, a - b);

        for (int i = 0; i < n; ++i) {
            if (group[i] == 'A' && a + cost[i] <= t) {
                if (!dp[a + cost[i]][b]) {
                    dp[a + cost[i]][b] = true;
                    q.push({a + cost[i], b});
                }
            } else if (group[i] == 'B' && b + cost[i] <= t) {
                if (!dp[a][b + cost[i]]) {
                    dp[a][b + cost[i]] = true;
                    q.push({a, b + cost[i]});
                }
            }
        }
    }

    return ans;
}

int main() {
    std::clock_t startTime = std::clock();
    cin >> n >> t;

    for (int i = 0; i < n; ++i) {
        int x, p, k;
        char c;
        cin >> x >> p >> c >> k;

        cost[x] = p;
        group[x] = c;

        for (int j = 0; j < k; ++j) {
            int v;
            cin >> v;
            graph[x].push_back(v);
        }
    }

    cout << solve() << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}