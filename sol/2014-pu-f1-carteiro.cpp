#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
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
    
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}