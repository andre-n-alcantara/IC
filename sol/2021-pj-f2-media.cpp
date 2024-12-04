#include <iostream>
using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;
    long long minC = (A + B) / 2 - A;
    if ((A + B + minC) % 3 != 0) minC--;
    cout << minC << endl;
    return 0;
}