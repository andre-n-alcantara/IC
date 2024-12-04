
#include <iostream>
#include <vector>

using namespace std;

const intBURACOS[4][2] = {{1, 3}, {2, 3}, {2, 5}, {5, 4}};
const int DX[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
const int DY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    int N;
    cin >> N;
    vector<int> movimentos(N);
    for (int i = 0; i < N; i++)
        cin >> movimentos[i];

    int x = 4, y = 3;
    int cont = 0;

    for (int i = 0; i < N; i++) {
        int nx = x + DX[movimentos[i] - 1];
        int ny = y + DY[movimentos[i] - 1];

        bool buraco = false;
        for (int j = 0; j < 4; j++)
            if (nx == BURACOS[j][0] && ny == BURACOS[j][1])
                buraco = true;

        if (buraco)
            break;

        x = nx;
        y = ny;
        cont++;
    }

    cout << cont + 1 << endl;

    return 0;
}
