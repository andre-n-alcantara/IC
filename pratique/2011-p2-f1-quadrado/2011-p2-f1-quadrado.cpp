#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateArithmeticSquare(int N, int S) {
    vector<vector<int>> square(N, vector<int>(N));

    int num = -(N * (N - 1) / 2);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            square[i][j] = num++;
        }
    }

    int target = S - (N * (N * (N - 1) / 2));
    for (int i = 0; i < N; i++) {
        square[i][i] += target / N;
    }

    return square;
}

int main() {
    int N, S;
    cin >> N >> S;

    vector<vector<int>> square = generateArithmeticSquare(N, S);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << square[i][j] << " ";
        }
        cout << endl;
    }

    
return 0;
}