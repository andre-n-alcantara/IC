#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> v(M);
    for (int i = 0; i < M; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int cnt = 0;
    int curr = 1;
    for (int i = 0; i < M; i++) {
        if (v[i] >= curr) {
            cnt++;
            curr = v[i] + 1;
        }
    }

    cout << cnt << endl;

    return 0;
}