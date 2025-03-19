#include <ctime>
#include <iostream>

using namespace std;

long long countPositions(int n, int t) {
    if (t == 0) {
        return n;
    } else if (t == 1) {
        return n * (n - 1);
    } else {
        return (n * (n - 1) * (n - 2)) / 2;
    }
}

int main() {
    int n, t;
    cin >> n >> t;
    cout << countPositions(n, t) << endl;
    
return 0;
}