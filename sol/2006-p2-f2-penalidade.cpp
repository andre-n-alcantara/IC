#include <ctime>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int minPenalty(int n, vector<vector<int>>& board) {
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {1, 0})); // dp[i][j] = {cost, penalty}

    dp[0][0] = {board[0][0], 0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) continue;
            if (i > 0) {
                int cost = dp[i-1][j].first * board[i][j];
                int penalty = dp[i-1][j].second + (cost == 0 ? 0 : (int)log10(cost) + 1);
                if (dp[i][j].first == 1 || penalty < dp[i][j].second) dp[i][j] = {cost, penalty};
            }
            if (j > 0) {
                int cost = dp[i][j-1].first * board[i][j];
                int penalty = dp[i][j-1].second + (cost == 0 ? 0 : (int)log10(cost) + 1);
                if (dp[i][j].first == 1 || penalty < dp[i][j].second) dp[i][j] = {cost, penalty};
            }
        }
    }

    return dp[n-1][n-1].second;
}

int main() {
    std::clock_t startTime = std::clock();
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    cout << minPenalty(n, board) << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}