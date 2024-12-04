#include <iostream>

using namespace std;

int main() {
    int A, B, C, H, L;
    cin >> A >> B >> C >> H >> L;
    if ((A <= H && B <= L) || (A <= L && B <= H) || (B <= H && A <= L) || (B <= L && A <= H) || (C <= H && A <= L) || (C <= L && A <= H) || (C <= H && B <= L) || (C <= L && B <= H))
        cout << "S" << endl;
    else
        cout << "N" << endl;
    return 0;
}