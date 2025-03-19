#include <ctime>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int S, T, P;
    cin >> S >> T >> P;

    vector<int> height(S + 1);
    for (int i = 1; i <= S; i++)
        cin >> height[i];

    vector<vector<int>> tunnels(S + 1);
    for (int i = 0; i < T; i++) {
        int I, J;
        cin >> I >> J;
        tunnels[I].push_back(J);
        tunnels[J].push_back(I);
    }

    vector<bool> visited(S + 1, false);
    int max_salões = 0;

    queue<int> q;
    q.push(P);
    visited[P] = true;

    while (!q.empty()) {
        int sala = q.front();
        q.pop();

        for (int tunnel : tunnels[sala]) {
            if (!visited[tunnel] && height[sala] > height[tunnel]) {
                q.push(tunnel);
                visited[tunnel] = true;
                max_salões++;
            }
        }
    }

    cout << max_salões << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}