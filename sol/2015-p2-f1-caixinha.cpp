#include <iostream>

using namespace std;

long long dp[101][101][101];

long long solve(int n, int m, int a, int b, int c) {
    if (a > m || b > m || c > m) return 0;
    if (a + b + c == n) return 1;
    if (dp[a][b][c] != -1) return dp[a][b][c];
    long long ans = 0;
    for (int i = 0; i <= m; i++) {
        ans += solve(n, m, a + i, b, c);
        ans += solve(n, m, a, b + i, c);
        ans += solve(n, m, a, b, c + i);
    }
    dp[a][b][c] = ans;
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    cout << solve(n, m, 0, 0, 0) << endl;
    return 0;
}