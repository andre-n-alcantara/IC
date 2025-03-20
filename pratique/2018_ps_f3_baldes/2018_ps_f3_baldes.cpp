#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> buckets(N);
    for (int i = 0; i < N; i++) {
        cin >> buckets[i];
    }

    for (int i = 0; i < M; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int p, idx;
            cin >> p >> idx;
            buckets[idx - 1] += p;
        } else {
            int a, b;
            cin >> a >> b;
            vector<int> temp(b - a + 1);
            copy(buckets.begin() + a - 1, buckets.begin() + b, temp.begin());
            sort(temp.begin(), temp.end());
            int max_diff = temp.back() - temp.front();
            cout << max_diff << endl;
        }
    }

    return 0;
}