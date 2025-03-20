#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isLegal(const vector<vector<int>>& mat, int lin, int col) {
    for (int i = 2; i <= lin; i++) {
        for (int j = 2; j <= col; j++) {
            if (mat[0][0] + mat[i-1][j-1] > mat[0][j-1] + mat[i-1][0]) {
                return false;
            }
        }
    }
    return true;
}

int maxSuperLegalSubmatrix(const vector<vector<int>>& mat) {
    int L = mat.size();
    int C = mat[0].size();
    int max_size = 0;

    for (int lin = 1; lin <= L; lin++) {
        for (int col = 1; col <= C; col++) {
            for (int i = 0; i <= L-lin; i++) {
                for (int j = 0; j <= C-col; j++) {
                    vector<vector<int>> submat(lin, vector<int>(col));
                    for (int k = 0; k < lin; k++) {
                        for (int l = 0; l < col; l++) {
                            submat[k][l] = mat[i+k][j+l];
                        }
                    }
                    if (isLegal(submat, lin, col)) {
                        max_size = max(max_size, lin*col);
                    }
                }
            }
        }
    }

    return max_size;
}

int main() {
    int L, C;
    cin >> L >> C;

    vector<vector<int>> mat(L, vector<int>(C));
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            cin >> mat[i][j];
        }
    }

    cout << maxSuperLegalSubmatrix(mat) << endl;

    return 0;
}