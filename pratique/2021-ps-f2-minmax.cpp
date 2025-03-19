#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int sumDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int S, A, B;
    cin >> S >> A >> B;

    int minNum = B + 1;
    int maxNum = A - 1;

    for (int i = A; i <= B; i++) {
        if (sumDigits(i) == S) {
            if (i < minNum) minNum = i;
            if (i > maxNum) maxNum = i;
        }
    }

    cout << minNum << endl << maxNum << endl;

    return 0;
}