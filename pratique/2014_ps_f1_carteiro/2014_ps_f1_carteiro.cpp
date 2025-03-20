#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> houses(N);
    for (int i = 0; i < N; i++) {
        cin >> houses[i];
    }
    vector<int> deliveries(M);
    for (int i = 0; i < M; i++) {
        cin >> deliveries[i];
    }
    int time = 0;
    int currentPosition = houses[0];
    for (int i = 0; i < M; i++) {
        int deliveryHouse = deliveries[i];
        time += abs(deliveryHouse - currentPosition);
        currentPosition = deliveryHouse;
    }
    cout << time << endl;
    return 0;
}