
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int inv = 0;
    for (int i = 0; i < n; i++) {
        inv += (i + 1) - a[i];
    }
    cout << inv << endl;
    return 0;
}
