#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K, C;
    cin >> N >> K >> C;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int sum = 0;
    for (int i = K * C; i < N; i++) {
        sum += A[i];
    }

    cout << sum << endl;

    return 0;
}