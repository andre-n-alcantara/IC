#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canFormTriangle(int a, int b, int c) {
    return a + b > c && a + c > b && b + c > a;
}

int main() {
    int n;
    cin >> n;
    vector<int> sticks(n);
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }
    sort(sticks.begin(), sticks.end(), greater<int>());

    for (int i = n - 1; i >= 3; i--) {
        if (canFormTriangle(sticks[0], sticks[1], sticks[i])) {
            cout << i << endl;
            
return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}