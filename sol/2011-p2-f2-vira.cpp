
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 10007;

int countSolutions(vector<char>& state) {
    int n = state.size();
    vector<int> dp(1 << n, 0);
    dp[0] = 1;

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                if (state[i] == 'P') {
                    int nextMask = mask ^ (1 << i);
                    if (i - 1 >= 0) nextMask ^= 1 << (i - 1);
                    if (i + 1 < n) nextMask ^= 1 << (i + 1);
                    dp[mask] += dp[nextMask];
                    dp[mask] %= MOD;
                }
            }
        }
    }

    int total = 0;
    for (int i = 0; i < (1 << n); i++) {
        total += dp[i];
        total %= MOD;
    }

    return total;
}

int main() {
    int n;
    cin >> n;

    vector<char> state(n);
    for (int i = 0; i < n; i++) {
        cin >> state[i];
    }

    cout << countSolutions(state) << endl;

    return 0;
}
