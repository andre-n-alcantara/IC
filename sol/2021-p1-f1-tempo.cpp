
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
        int X;
        cin >> type >> X;

        if (type == 'R') {
            lastReceived[X] = i;
        } else if (type == 'E') {
            if (lastReceived.count(X)) {
                int timp = i - lastReceived[X];
                if (responseTime.count(X)) {
                    responseTime[X] += timp;
                } else {
                    responseTime[X] = timp;
                }
                lastReceived.erase(X);
            }
        } else if (type == 'T') {
            for (auto& p : lastReceived) {
                p.second += X;
            }
        }
    }

    vector<pair<int, int>> friends;
    for (auto& p : responseTime) {
        friends.push_back(make_pair(p.first, p.second));
    }
    sort(friends.begin(), friends.end());

    for (auto& p : friends) {
        cout << p.first << " " << p.second << endl;
    }

    for (auto& p : lastReceived) {
        cout << p.first << " -1" << endl;
    }

    return 0;
}
