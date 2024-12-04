
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isMagicSquare(vector<vector<int>>& square) {
    int n = square.size();
    int expectedSum = n * (n * n + 1) / 2;

    // check rows
    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += square[i][j];
        }
        if (rowSum != expectedSum) return false;
    }

    // check columns
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++) {
            colSum += square[i][j];
        }
        if (colSum != expectedSum) return false;
    }

    // check diagonals
    int diag1Sum = 0, diag2Sum = 0;
    for (int i = 0; i < n; i++) {
        diag1Sum += square[i][i];
        diag2Sum += square[i][n - i - 1];
    }
    if (diag1Sum != expectedSum || diag2Sum != expectedSum) return false;

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> square(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> square[i][j];
        }
    }

    if (isMagicSquare(square)) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += square[0][i];
        }
        cout << sum << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
