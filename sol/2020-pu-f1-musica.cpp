#include <ctime>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N, M, C;
    cin >> N >> M >> C;

    vector<pair<int, int>> friends(N);
    for (int i = 0; i < N; i++) {
        cin >> friends[i].first >> friends[i].second;
    }

    unordered_map<int, int> hateCount(M + 1, 0);
    vector<int> sharedMusic(N, C);
    int changes = 0;

    while (true) {
        bool changed = false;
        for (int i = 0; i < N; i++) {
            if (sharedMusic[i] == friends[i].second) {
                hateCount[sharedMusic[i]]++;
                if (hateCount[sharedMusic[i]] == 1) {
                    sharedMusic[i] = friends[i].first;
                    changes++;
                    changed = true;
                } else if (hateCount[sharedMusic[i]] > 1) {
                    sharedMusic[i] = friends[i].first;
                    changes++;
                    changed = true;
                    break;
                }
            }
        }
        if (!changed) break;
    }

    if (changes == 0) cout << -1 << endl;
    else cout << changes << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}