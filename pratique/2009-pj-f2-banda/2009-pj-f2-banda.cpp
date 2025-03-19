#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> entrosamento(N+1, vector<int>(N+1, 0));

    for (int i = 0; i < M; i++) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        entrosamento[X][Y] = Z;
        entrosamento[Y][X] = Z;
    }

    int max_entrosamento = 0;
    int musica1, musica2, musica3;

    for (int i = 1; i <= N; i++) {
        for (int j = i+1; j <= N; j++) {
            for (int k = j+1; k <= N; k++) {
                int sum = entrosamento[i][j] + entrosamento[i][k] + entrosamento[j][k];
                if (sum > max_entrosamento) {
                    max_entrosamento = sum;
                    musica1 = i;
                    musica2 = j;
                    musica3 = k;
                }
            }
        }
    }

    cout << musica1 << " " << musica2 << " " << musica3 << endl;

    
return 0;
}