
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
        prices[i].first /= prices[i].second;
        prices[i].first *= 1000;
    }

    sort(prices.begin(), prices.end());

    printf("%.2f\n", prices[0].first);

    return 0;
}
