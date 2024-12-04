
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T, N;
    cin >> T >> N;
    vector<int> cities(N);
    for (int i = 0; i < N; i++) {
        cin >> cities[i];
    }
    sort(cities.begin(), cities.end());

    double min_interval = cities[0];
    for (int i = 1; i < N; i++) {
        min_interval = min(min_interval, (cities[i] - cities[i-1]) / 2.0);
    }
    min_interval = min(min_interval, (T - cities[N-1]) / 2.0);

    cout << fixed << setprecision(2) << min_interval << endl;

    return 0;
}
