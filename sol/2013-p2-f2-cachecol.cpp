#include <iostream>

using namespace std;

long long mod = 1000000007;

long long power(long long x, long long y) {
    long long res = 1;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}

int main() {
    long long n;
    cin >> n;
    long long ans = (power(3, n - 1) * 2) % mod;
    cout << ans << endl;
    return 0;
}