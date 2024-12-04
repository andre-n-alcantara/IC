
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double dp[201][201];
int N;
double F;
vector<int> areas;

double divide(int l, int r) {
    if (l == r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    double ans = 1e100;
    for (int i = l; i < r; i++) {
        double left = 0, right = 0;
        for (int j = l; j <= i; j++) left += areas[j];
        for (int j = i + 1; j <= r; j++) right += areas[j];
        ans = min(ans, F * max(left, right) + divide(l, i) + divide(i + 1, r));
    }
    return dp[l][r] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> F;
    areas.resize(N);
    for (int i = 0; i < N; i++) cin >> areas[i];
    fill(&dp[0][0], &dp[201][201], -1);
    printf("%.2f\n", divide(0, N - 1));
    return 0;
}
