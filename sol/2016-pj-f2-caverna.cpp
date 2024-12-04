
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> dp(N + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i - 1] + A[j] <= M) {
                dp[i] = min(dp[i], dp[j] + A[i - 1]);
            }
        }
    }

    int ans = *min_element(dp.begin(), dp.end());
    if (ans == 1e9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
