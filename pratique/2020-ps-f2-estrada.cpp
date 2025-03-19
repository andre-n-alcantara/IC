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
    double min_distance = T;
    for (int i = 0; i < N - 1; i++) {
        double distance = (cities[i + 1] - cities[i]) / 2.0;
        min_distance = min(min_distance, distance);
    }
    cout << fixed << setprecision(2) << min_distance << endl;
    return 0;
}