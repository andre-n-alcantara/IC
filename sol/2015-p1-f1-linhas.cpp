#include <ctime>
#include <bits/stdc++.h>
using namespace std;

int main() {
    std::clock_t startTime = std::clock();
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
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}