#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    map<int, int> responseTime;
    map<int, bool> hasResponse;

    int time = 0;
    for (int i = 0; i < N; i++) {
        char type;
        int friendId;
        cin >> type >> friendId;

        if (type == 'R') {
            time++;
            responseTime[friendId] = time;
            hasResponse[friendId] = false;
        } else if (type == 'E') {
            if (hasResponse[friendId]) {
                time++;
            } else {
                int startTime = responseTime[friendId];
                time -= startTime;
                responseTime[friendId] = time;
                hasResponse[friendId] = true;
            }
        } else if (type == 'T') {
            time += friendId;
        }
    }

    vector<pair<int, int>> results;
    for (auto it = responseTime.begin(); it != responseTime.end(); it++) {
        int friendId = it->first;
        int totalTime = hasResponse[friendId] ? it->second : -1;
        results.push_back(make_pair(friendId, totalTime));
    }

    sort(results.begin(), results.end());

    for (auto result : results) {
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}