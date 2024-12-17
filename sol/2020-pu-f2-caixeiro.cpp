#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

vector<vector<int>> dp, cost;
int n;

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) return 0;
    if (dp[mask][pos] != -1) return dp[mask][pos];
    int ans = INF;
    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) {
            ans = min(ans, cost[pos][i] + tsp(mask | (1 << i), i));
        }
    }
    return dp[mask][pos] = ans;
}

int main() {
    std::clock_t startTime = std::clock();
    cin >> n;
    cost.assign(n, vector<int>(n, INF));
    for (int i = 0, a, b, t; i < n * (n - 1) / 2; i++) {
        cin >> a >> b >> t;
        cost[a - 1][b - 1] = cost[b - 1][a - 1] = t;
    }
    dp.assign(1 << n, vector<int>(n, -1));
    int ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min(ans, tsp(1 << i, i));
    }
    cout << ans << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}