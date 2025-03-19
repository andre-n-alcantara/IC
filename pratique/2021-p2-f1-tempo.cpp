#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    map<int, int> responseTime;
    map<int, int> lastReceived;

    for (int i = 0; i < N; i++) {
        char type;
        int x;
        cin >> type >> x;

        if (type == 'R') {
            lastReceived[x] = i;
        } else if (type == 'E') {
            if (lastReceived.find(x) != lastReceived.end()) {
                int time = i - lastReceived[x];
                responseTime[x] = (responseTime.find(x) == responseTime.end() ? 0 : responseTime[x]) + time;
            }
        } else {
            i -= x;
        }
    }

    vector<pair<int, int>> friends;
    for (auto it = responseTime.begin(); it != responseTime.end(); it++) {
        friends.push_back({it->first, it->second});
    }

    sort(friends.begin(), friends.end());

    for (auto friendInfo : friends) {
        cout << friendInfo.first << " " << friendInfo.second << endl;
    }

    return 0;
}