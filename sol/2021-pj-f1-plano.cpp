#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N, M;
    cin >> N >> M;
    vector<int> V(M);
    for (int i = 0; i < M; i++) {
        cin >> V[i];
    }
    int ans = 0, last = 0;
    for (int i = 0; i < M; i++) {
        if (V[i] >= last) {
            ans++;
            last = V[i];
        }
    }
    cout << ans << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}