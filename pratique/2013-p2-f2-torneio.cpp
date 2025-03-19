#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int count_losses(int n, int k, vector<int> skills) {
    vector<int> wins(1 << n, 0);
    wins[0] = 1;
    for (int i = 0; i < n; i++) {
        vector<int> next_wins(1 << n, 0);
        for (int j = 0; j < (1 << n); j++) {
            int winner = -1;
            for (int p = 0; p < (1 << i); p++) {
                int player = (j >> (n - i - 1)) & ((1 << i) - 1);
                if (skills[player] > skills[winner]) {
                    winner = player;
                }
            }
            next_wins[j] = wins[j ^ (1 << (n - i - 1))] * (winner != 0);
        }
        wins = next_wins;
    }
    int losses = 0;
    for (int i = 0; i < (1 << n); i++) {
        if (((i >> (n - k + 1)) & (1 << (k - 1))) == 0) {
            losses = (losses + wins[i]) % MOD;
        }
    }
    return losses;
}

int main() {
    std::clock_t startTime = std::clock();
    int n, k;
    cin >> n >> k;
    vector<int> skills(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        cin >> skills[i];
    }
    cout << count_losses(n, k, skills) << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}