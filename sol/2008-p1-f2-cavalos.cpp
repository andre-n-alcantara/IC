
#include <iostream>
#include <vector>

using namespace std;

int solve(int M, int N) {
    if (M == 1) return N;
    if (N == 1) return M;
    if (M == 2) return N / 2 * 2;
    if (N == 2) return M / 2 * 2;
    return (M * N + 1) / 2;
}

int main() {
    int M, N;
    cin >> M >> N;
    cout << solve(M, N) << endl;
    return 0;
}
