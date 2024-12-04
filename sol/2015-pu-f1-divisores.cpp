
#include <iostream>
using namespace std;

int countDivisors(int n) {
    int count = 1;
    for (int i = 2; i * i <= n; i++) {
        int power = 0;
        while (n % i == 0) {
            n /= i;
            power++;
        }
        if (power > 0) {
            count *= (power + 1);
        }
    }
    if (n > 1) {
        count *= 2;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << countDivisors(n) << endl;
    return 0;
}
