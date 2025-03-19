#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> board(N);
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    int maxFood = 0;
    int currentFood = 0;
    bool hasGhost = false;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 'o') {
                currentFood++;
            } else if (board[i][j] == 'A') {
                hasGhost = true;
                if (hasGhost && currentFood > maxFood) {
                    maxFood = currentFood;
                }
                currentFood = 0;
            }
        }
        if (i % 2 == 1) {
            for (int j = N - 1; j >= 0; j--) {
                if (board[i][j] == 'o') {
                    currentFood++;
                } else if (board[i][j] == 'A') {
                    hasGhost = true;
                    if (hasGhost && currentFood > maxFood) {
                        maxFood = currentFood;
                    }
                    currentFood = 0;
                }
            }
        }
    }

    if (!hasGhost && currentFood > maxFood) {
        maxFood = currentFood;
    }

    cout << maxFood << endl;

    
return 0;
}