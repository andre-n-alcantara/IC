#include <iostream>
using namespace std;

int main() {
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;

    int count = 0;
    if(N >= X) {
        N -= X;
        count++;
    }
    if(N >= Y) {
        N -= Y;
        count++;
    }
    if(N >= Z) {
        N -= Z;
        count++;
    }

    cout << count << endl;

    return 0;
}