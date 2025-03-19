#include <ctime>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int independenceDegree(string S1, string S2) {
    int N = S1.length(), M = S2.length();
    vector<vector<bool>> dp(N + 1, vector<bool>(M + 1, false));

    for (int i = 0; i <= N; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (S1[i - 1] == S2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    for (int i = N; i >= 1; i--) {
        if (!dp[i][M]) {
            return i;
        }
    }

    return 0;
}

int main() {
    std::clock_t startTime = std::clock();
    int N, M;
    string S1, S2;

    cin >> N >> M;
    cin >> S1 >> S2;

    cout << independenceDegree(S1, S2) << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}