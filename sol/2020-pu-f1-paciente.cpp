#include <ctime>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N, C;
    cin >> N >> C;

    vector<bool> infected(N + 1, false);
    vector<int> parent(N + 1, -1);

    for (int i = 0; i < C; i++) {
        int P, I;
        cin >> P >> I;
        infected[P] = true;
        for (int j = 0; j < I; j++) {
            int Xi;
            cin >> Xi;
            infected[Xi] = true;
            parent[Xi] = P;
        }
    }

    unordered_set<int> zeros;
    for (int i = 1; i <= N; i++) {
        if (!infected[i]) continue;
        if (parent[i] == -1) zeros.insert(i);
    }

    for (int zero : zeros) {
        cout << zero << endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}