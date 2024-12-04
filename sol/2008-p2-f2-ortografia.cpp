#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int minDistance(string a, string b) {
    int m = a.size(), n = b.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = min(min(dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]), dp[i - 1][j] + 1), dp[i][j - 1] + 1);
    return dp[m][n];
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> dict(N);
    for (int i = 0; i < N; i++)
        cin >> dict[i];
    for (int i = 0; i < M; i++) {
        string word;
        cin >> word;
        bool first = true;
        for (const string& d : dict) {
            if (minDistance(word, d) <= 2) {
                if (first) {
                    cout << d;
                    first = false;
                } else {
                    cout << " " << d;
                }
            }
        }
        cout << endl;
    }
    return 0;
}