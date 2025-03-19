#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<double, int>> prices(N);

    for (int i = 0; i < N; i++) {
        cin >> prices[i].first >> prices[i].second;
        prices[i].first /= prices[i].second / 1000.0;
    }

    sort(prices.begin(), prices.end());

    cout << fixed << setprecision(2) << prices[0].first * 1000 << endl;

    return 0;
}