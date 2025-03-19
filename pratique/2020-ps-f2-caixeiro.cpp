#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1501;
const int INF = 1e9;

int n, dp[1 << MAXN][MAXN], d[MAXN][MAXN];

void floyd_warshall() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = (i == j ? 0 : INF);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            scanf("%d %d %d", &i, &j, &d[i][j]);
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int tsp(int mask, int v) {
    if (dp[mask][v] != -1) return dp[mask][v];
    int ans = INF;
    for (int i = 1; i <= n; i++)
        if ((mask & (1 << i)) && i != v)
            ans = min(ans, tsp(mask ^ (1 << i), i) + d[i][v]);
    return dp[mask][v] = ans;
}

int main() {
    scanf("%d", &n);
    memset(dp, -1, sizeof dp);
    floyd_warshall();
    int ans = INF;
    for (int i = 1; i <= n; i++)
        ans = min(ans, tsp((1 << n) - (1 << i), i) + d[i][1]);
    printf("%d\n", ans);
    return 0;
}