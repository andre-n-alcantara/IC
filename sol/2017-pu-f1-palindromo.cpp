#include <ctime>
#include <iostream>
#include <string>

using namespace std;

int minCut(string s) {
    int n = s.size();
    int dp[n];
    fill(dp, dp + n, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (s.substr(j, i - j + 1) == string(s.substr(j, i - j + 1).rbegin(), s.substr(j, i - j + 1).rend())) {
                if (j == 0)
                    dp[i] = 0;
                else
                    dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }
    return dp[n - 1] + 1;
}

int main() {
    std::clock_t startTime = std::clock();
    int N;
    cin >> N;
    string s;
    cin >> s;
    cout << minCut(s) << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}