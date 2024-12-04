
#include <iostream>
#include <vector>

using namespace std;

int maxMarked(vector<int> sequence) {
    int n = sequence.size();
    vector<int> dp(n, 0);

    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + (sequence[i] != sequence[i-1]));
    }

    return dp[n-1];
}

int main() {
    int n;
    cin >> n;

    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    cout << maxMarked(sequence) << endl;

    return 0;
}
