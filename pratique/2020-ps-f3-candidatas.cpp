#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int count_candidates(vector<int>& seq, int left, int right) {
    int count = 0;
    for (int i = left; i <= right; i++) {
        int max_gcd = 0;
        for (int j = i; j <= right; j++) {
            int gcd_val = gcd(seq[i - 1], seq[j - 1]);
            if (gcd_val > 1) max_gcd = max(max_gcd, gcd_val);
            if (max_gcd > 1) count++;
        }
    }
    return count;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> seq(N);
    for (int i = 0; i < N; i++) {
        cin >> seq[i];
    }

    for (int i = 0; i < M; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int I, V;
            cin >> I >> V;
            seq[I - 1] = V;
        } else {
            int E, D;
            cin >> E >> D;
            cout << count_candidates(seq, E, D) << endl;
        }
    }

    return 0;
}