#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> sum(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    unordered_map<int, int> mp;
    mp[0] = 1;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += mp[sum[i] - K];
        mp[sum[i]]++;
    }
    cout << ans << endl;
    return 0;
}