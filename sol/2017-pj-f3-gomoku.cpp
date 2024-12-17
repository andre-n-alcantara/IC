#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

bool checkWin(const vector<vector<int>>& board, int player) {
    int N = 15;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == player) {
                // Check horizontal
                int count = 0;
                for (int k = 0; k < 5; ++k) {
                    if (j + k < N && board[i][j + k] == player)
                        count++;
                    else
                        break;
                }
                if (count == 5) return true;

                // Check vertical
                count = 0;
                for (int k = 0; k < 5; ++k) {
                    if (i + k < N && board[i + k][j] == player)
                        count++;
                    else
                        break;
                }
                if (count == 5) return true;

                // Check diagonal (top-left to bottom-right)
                count = 0;
                for (int k = 0; k < 5; ++k) {
                    if (i + k < N && j + k < N && board[i + k][j + k] == player)
                        count++;
                    else
                        break;
                }
                if (count == 5) return true;

                // Check diagonal (bottom-left to top-right)
                count = 0;
                for (int k = 0; k < 5; ++k) {
                    if (i - k >= 0 && j + k < N && board[i - k][j + k] == player)
                        count++;
                    else
                        break;
                }
                if (count == 5) return true;
            }
        }
    }
    return false;
}

int main() {
    std::clock_t startTime = std::clock();
    vector<vector<int>> board(15, vector<int>(15));
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            cin >> board[i][j];
        }
    }

    if (checkWin(board, 1)) cout << 1 << endl;
    else if (checkWin(board, 2)) cout << 2 << endl;
    else cout << 0 << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}