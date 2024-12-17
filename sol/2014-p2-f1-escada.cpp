#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N, M;
    cin >> N >> M;

    vector<vector<int>> matrix(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    bool isStaircase = true;

    for (int i = 0; i < N; i++) {
        bool hasNonZero = false;
        int firstNonZeroColumn = -1;

        for (int j = 0; j < M; j++) {
            if (matrix[i][j] != 0) {
                if (!hasNonZero) {
                    hasNonZero = true;
                    firstNonZeroColumn = j;
                } else if (j != firstNonZeroColumn) {
                    isStaircase = false;
                    break;
                }
            }
        }

        if (!hasNonZero) break;

        for (int k = i + 1; k < N; k++) {
            for (int j = 0; j <= firstNonZeroColumn; j++) {
                if (matrix[k][j] != 0) {
                    isStaircase = false;
                    break;
                }
            }
            if (!isStaircase) break;
        }

        if (!isStaircase) break;
    }

    cout << (isStaircase ? "S" : "N") << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}