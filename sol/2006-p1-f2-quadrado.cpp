
#include <iostream>
using namespace std;

int main() {
    int matrix[3][3] = {0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }

    int sum = (matrix[0][0] + matrix[0][1] + matrix[0][2]);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][j] = sum - (matrix[(i+1)%3][j] + matrix[(i+2)%3][j]);
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
