#include <iostream>
#include <vector>

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
    int currentHouse = houses[0];
    
    for (int delivery : deliveries) {
        time += abs(delivery - currentHouse);
        currentHouse = delivery;
    }
    
    cout << time << endl;
    
    return 0;
}