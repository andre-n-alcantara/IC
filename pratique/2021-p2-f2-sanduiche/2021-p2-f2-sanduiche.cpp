#include <ctime>
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int MAX_N = 21;

int n, m;
vector<pair<int, int>> forbidden;
bitset<MAX_N> dp[1 << MAX_N];

int count_sandwiches() {
    dp[0].set();
    for (int mask = 0; mask < (1 << n); mask++) {
        if (!dp[mask]) continue;
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                bool ok = true;
                for (auto &p : forbidden) {
                    if ((mask & (1 << (p.first - 1))) && ((mask | (1 << i)) & (1 << (p.second - 1)))) {
                        ok = false;
                        break;
                    }
                }
                if (ok) dp[mask | (1 << i)] = dp[mask];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        ans += dp[i];
    }
    return ans - 1; // subtract empty sandwich
}

int main() {
    cin >> n >> m;
    forbidden.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> forbidden[i].first >> forbidden[i].second;
    }
    cout << count_sandwiches() << endl;
    
return 0;
}