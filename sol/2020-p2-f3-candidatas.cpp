#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int countCandidates(vector<int>& seq, int l, int r) {
    int count = 0;
    for (int i = l; i <= r; i++) {
        int g = seq[i];
        for (int j = i; j <= r; j++) {
            g = gcd(g, seq[j]);
            if (g > 1) count++;
        }
    }
    return count;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> seq(N);
    for (int i = 0; i < N; i++) cin >> seq[i];

    for (int i = 0; i < M; i++) {
        int T, I, V, E, D;
        cin >> T;
        if (T == 1) {
            cin >> I >> V;
            seq[I - 1] = V;
        } else {
            cin >> E >> D;
            cout << countCandidates(seq, E - 1, D - 1) << endl;
        }
    }

    return 0;
}