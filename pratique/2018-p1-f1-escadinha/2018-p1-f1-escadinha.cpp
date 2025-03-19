#include <ctime>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> seq(n);
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    unordered_map<int, int> diffCnt;
    int maxLen = 0, cnt = 0;

    for (int i = 1; i < n; i++) {
        int diff = seq[i] - seq[i-1];
        if (diff != 0) {
            diffCnt[diff]++;
            maxLen = max(maxLen, diffCnt[diff]);
        }
    }

    for (auto it = diffCnt.begin(); it != diffCnt.end(); it++) {
        if (it->second == maxLen) {
            cnt++;
        }
    }

    cout << cnt << endl;

    
return 0;
}