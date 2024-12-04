
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> pessoas(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> pessoas[i];
    }
    vector<int> prefixSum(N + 1);
    for (int i = 1; i <= N; i++) {
        prefixSum[i] = prefixSum[i - 1] + pessoas[i];
    }
    for (int i = 0; i < Q; i++) {
        int tipo, K, P;
        cin >> tipo >> K;
        if (tipo == 0) {
            cin >> P;
            pessoas[K] = P;
        } else {
            cout << prefixSum[K] << endl;
        }
    }
    return 0;
}
