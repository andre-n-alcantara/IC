#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cout << (n % (m + 1) == 0 ? "Carlos" : "Paula") << endl;
    return 0;
}