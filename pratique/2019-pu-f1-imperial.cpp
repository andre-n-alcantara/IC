#include <iostream>
#include <vector>

using namespace std;

int maxMarked(vector<int>& seq) {
    int n = seq.size();
    vector<int> dp(n, 1);

    int maxCount = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (seq[i] != seq[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        maxCount = max(maxCount, dp[i]);
    }

    return maxCount;
}

int main() {
    int n;
    cin >> n;

    vector<int> seq(n);
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    int maxMarkedCount = maxMarked(seq);
    cout << maxMarkedCount << endl;

    return 0;
}