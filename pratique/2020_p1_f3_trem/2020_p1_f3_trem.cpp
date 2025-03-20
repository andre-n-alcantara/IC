#include <ctime>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_STATIONS = 1e4 + 10;
const int MAX_TRACKS = 2e4 + 10;

vector<pair<int, int>> tracks[MAX_STATIONS];
int distance[MAX_STATIONS];

int dijkstra(int start, int end, int train_length) {
    fill(distance, distance + MAX_STATIONS, INT_MAX);
    distance[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int curr_dist = pq.top().first;
        int curr_station = pq.top().second;
        pq.pop();
        if (curr_dist > distance[curr_station]) continue;
        for (auto &track : tracks[curr_station]) {
            int next_dist = curr_dist + track.second;
            if (next_dist <= distance[track.first] && next_dist <= train_length) {
                distance[track.first] = next_dist;
                pq.push({next_dist, track.first});
            }
        }
    }
    return distance[end] == INT_MAX ? -1 : distance[end];
}

int main() {
    int E, R;
    cin >> E >> R;
    for (int i = 0; i < R; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        tracks[A].push_back({B, C});
        tracks[B].push_back({A, C});
    }
    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int X, T;
        cin >> X >> T;
        cout << dijkstra(X, X, T) << endl;
    }
    
return 0;
}