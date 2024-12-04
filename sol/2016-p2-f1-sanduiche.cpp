
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    vector<int> prefixSum(N + 1, 0);
    for (int i = 0; i < N; i++) {
        prefixSum[i + 1] = prefixSum[i] + C[i];
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (prefixSum[j + 1] - prefixSum[i] == D) {
                count++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 2; j < N; j++) {
            if (C[i] + C[j] + prefixSum[N] - prefixSum[j + 1] == D) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
