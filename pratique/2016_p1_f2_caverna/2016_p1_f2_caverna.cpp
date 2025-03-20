#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = -1;
    for (int i = 0; i < (1 << N); i++) {
        int sum = 0;
        int prev = 0;
        bool ok = true;
        for (int j = 0; j < N; j++) {
            int curr = A[j] + prev;
            if (curr > M) {
                ok = false;
                break;
            }
            sum += curr;
            prev = curr;
        }
        if (ok && (ans == -1 || sum < ans)) {
            ans = sum;
        }
    }

    cout << ans << endl;
    return 0;
}