#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int L, C, M, N;
    cin >> L >> C >> M >> N;

    vector<vector<int>> plantation(L, vector<int>(C));
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            cin >> plantation[i][j];
        }
    }

    int max_margaridas = 0;
    for (int i = 0; i <= L - M; i++) {
        for (int j = 0; j <= C - N; j++) {
            int sum = 0;
            for (int k = i; k < i + M; k++) {
                for (int l = j; l < j + N; l++) {
                    sum += plantation[k][l];
                }
            }
            max_margaridas = max(max_margaridas, sum);
        }
    }

    cout << max_margaridas << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}