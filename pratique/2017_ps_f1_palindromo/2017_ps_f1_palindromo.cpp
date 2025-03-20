#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}

int minCut(string s) {
    int n = s.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (isPalindrome(s.substr(j - 1, i - j + 1))) {
                dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }
    return dp[n] - 1;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << minCut(s) << endl;
    return 0;
}