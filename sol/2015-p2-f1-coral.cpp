
#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((a == b && c == d) || (a == c && b == d) || (a == d && b == c))
        cout << "F" << endl;
    else
        cout << "V" << endl;
    return 0;
}
