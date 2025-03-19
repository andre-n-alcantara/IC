#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> heights(N);
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }
    sort(heights.begin(), heights.end());
    int max_cuts = 0;
    for (int i = 0; i < N; i++) {
        max_cuts = max(max_cuts, (N - i) / (i + 1) + 1);
    }
    cout << max_cuts << endl;
    
return 0;
}