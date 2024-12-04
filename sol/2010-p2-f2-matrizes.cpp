#include <iostream>

using namespace std;

const int MOD = 1000000007;

long long mul(long long a, long long b) {
    return (a * b) % MOD;
}

int main() {
    int N, P, Q, R, S, X, Y, I, J;
    cin >> N >> P >> Q >> R >> S >> X >> Y >> I >> J;

    long long C = 0;
    for (int k = 1; k <= N; k++) {
        C = (C + mul((P * I + Q * k) % X, (R * k + S * J) % Y)) % MOD;
    }

    cout << C << endl;

    return 0;
}