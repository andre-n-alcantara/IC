#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<bool> occupied(N + 1, false);
    int ans = 0;
    for (int i = 1; i <= M; ++i) {
        int V;
        cin >> V;
        for (int j = 1; j <= V; ++j) {
            if (!occupied[j]) {
                occupied[j] = true;
                ++ans;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}