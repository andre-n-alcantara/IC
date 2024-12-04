#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> permutations(factorial(n));
    for (int i = 0; i < factorial(n) - 1; i++) {
        for (int j = 0; j < n; j++) {
            cin >> permutations[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            vector<int> permutation(n);
            for (int k = 0; k < n; k++) {
                permutation[k] = k + 1;
            }
            swap(permutation[i - 1], permutation[j - 1]);
            bool found = false;
            for (int k = 0; k < factorial(n) - 1; k++) {
                if (permutations[k] == permutation) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                for (int k = 0; k < n; k++) {
                    cout << permutation[k] << " ";
                }
                return 0;
            }
        }
    }

    return 0;
}