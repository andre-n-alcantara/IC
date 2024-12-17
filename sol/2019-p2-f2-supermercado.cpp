#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
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

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}