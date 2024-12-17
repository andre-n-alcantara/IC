#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
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

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}