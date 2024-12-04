
#include <iostream>
using namespace std;

int main() {
    long long L, N;
    cin >> L >> N;

    long long sum = 0;
    long long i = 1;
    while(L > 0 && N > 0) {
        long long side = min(L, i);
        sum += side * side;
        L -= side;
        i++;
        N--;
    }

    cout << sum << endl;

    return 0;
}
