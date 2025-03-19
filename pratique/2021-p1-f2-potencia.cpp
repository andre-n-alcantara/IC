#include <iostream>
using namespace std;

int potencia(int n, int p) {
    int result = 1;
    for (int i = 0; i < p; i++) {
        result *= n;
    }
    return result;
}

int main() {
    int N, Ti, sum = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> Ti;
        int n = Ti / 10;
        int p = Ti % 10;
        sum += potencia(n, p);
    }
    cout << sum << endl;
    return 0;
}