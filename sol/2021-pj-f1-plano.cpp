
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> V(M);
    for (int i = 0; i < M; i++) {
        cin >> V[i];
    }
    int ans = 0, last = 0;
    for (int i = 0; i < M; i++) {
        if (V[i] >= last) {
            ans++;
            last = V[i];
        }
    }
    cout << ans << endl;
    return 0;
}
