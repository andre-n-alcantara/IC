#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isLegal(vector<vector<int>>& mat, int l1, int c1, int l2, int c2) {
  for (int i = l1; i <= l2; i++) {
    for (int j = c1; j <= c2; j++) {
      if (i > l1 && j > c1 && mat[l1][c1] + mat[i][j] > mat[l1][j] + mat[i][c1]) {
        return false;
      }
    }
  }
  return true;
}

int maxSuperLegalSubmatrix(vector<vector<int>>& mat) {
  int L = mat.size();
  int C = mat[0].size();
  int ans = 0;

  for (int l1 = 0; l1 < L; l1++) {
    for (int c1 = 0; c1 < C; c1++) {
      for (int l2 = l1; l2 < L; l2++) {
        for (int c2 = c1; c2 < C; c2++) {
          if (l2 - l1 + 1 >= 2 && c2 - c1 + 1 >= 2 && isLegal(mat, l1, c1, l2, c2)) {
            ans = max(ans, (l2 - l1 + 1) * (c2 - c1 + 1));
          }
        }
      }
    }
  }

  return ans;
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