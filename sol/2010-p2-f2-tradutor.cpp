#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int countValidSequences(int N, string sequence) {
    int n = sequence.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, 2); j++) {
            int num = stoi(sequence.substr(i - j, j));
            if (num >= 1 && num <= N) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }

    return dp[n];
}

int main() {
    int N;
    string sequence;
    cin >> N >> sequence;
    cout << countValidSequences(N, sequence) << endl;
    return 0;
}