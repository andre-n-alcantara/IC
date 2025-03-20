#include <ctime>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> table(N, vector<int>(N, 0));
    vector<vector<map<int, int>>> row freq(N), col freq(N);

    for (int i = 0; i < Q; i++) {
        int op, x, r;
        cin >> op;
        cin >> x;

        if (op == 1 || op == 2) {
            cin >> r;
            if (op == 1) {
                for (int j = 0; j < N; j++) {
                    table[x-1][j] = r;
                    row_freq[x-1][r]++;
                }
            } else {
                for (int j = 0; j < N; j++) {
                    table[j][x-1] = r;
                    col_freq[x-1][r]++;
                }
            }
        } else if (op == 3) {
            map<int, int>& freq_map = row_freq[x-1];
            int max_freq = 0, max_val = 0;
            for (auto it = freq_map.begin(); it != freq_map.end(); it++) {
                if (it->second > max_freq || (it->second == max_freq && it->first > max_val)) {
                    max_freq = it->second;
                    max_val = it->first;
                }
            }
            cout << max_val << endl;
        } else if (op == 4) {
            map<int, int>& freq_map = col_freq[x-1];
            int max_freq = 0, max_val = 0;
            for (auto it = freq_map.begin(); it != freq_map.end(); it++) {
                if (it->second > max_freq || (it->second == max_freq && it->first > max_val)) {
                    max_freq = it->second;
                    max_val = it->first;
                }
            }
            cout << max_val << endl;
        }
    }

    
return 0;
}