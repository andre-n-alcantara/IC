#include <ctime>
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;
bool dp[MAX][MAX][MAX][MAX];

int main() {
    std::clock_t startTime = std::clock();
    ios::sync_with_stdio(false);
    cin.tie(0);

    int L, C;
    cin >> L >> C;

    vector<vector<int>> A(L, vector<int>(C));
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            cin >> A[i][j];
        }
    }

    for (int lin1 = 1; lin1 <= L; lin1++) {
        for (int col1 = 1; col1 <= C; col1++) {
            for (int lin2 = lin1; lin2 <= L; lin2++) {
                for (int col2 = col1; col2 <= C; col2++) {
                    if (lin1 == 1 && col1 == 1) {
                        dp[lin1][col1][lin2][col2] = true;
                    } else if (lin1 == 1) {
                        dp[lin1][col1][lin2][col2] = dp[1][1][lin2][col2-1] && A[0][col1-1] + A[lin2-1][0] <= A[0][0] + A[lin2-1][col1-1];
                    } else if (col1 == 1) {
                        dp[lin1][col1][lin2][col2] = dp[1][1][lin1-1][col2] && A[lin1-1][0] + A[0][col2-1] <= A[lin1-1][0] + A[0][col2-1];
                    } else {
                        dp[lin1][col1][lin2][col2] = dp[1][1][lin1-1][col2-1] && A[lin1-1][col1-1] + A[0][col2-1] <= A[lin1-1][col1-1] + A[0][col2-1];
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int lin1 = 1; lin1 <= L; lin1++) {
        for (int col1 = 1; col1 <= C; col1++) {
            for (int lin2 = lin1; lin2 <= L; lin2++) {
                for (int col2 = col1; col2 <= C; col2++) {
                    if (dp[lin1][col1][lin2][col2]) {
                        ans = max(ans, (lin2 - lin1 + 1) * (col2 - col1 + 1));
                    }
                }
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