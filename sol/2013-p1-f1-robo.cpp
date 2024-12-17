#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 1, 0, 0}; // Norte, Sul, Leste, Oeste
int dy[] = {0, 0, 1, -1}; // Norte, Sul, Leste, Oeste

int main() {
    std::clock_t startTime = std::clock();
    int L, C, A, B;
    cin >> L >> C >> A >> B;
    A--; B--; // Convertendo para indices 0-based

    vector<vector<int>> floor(L, vector<int>(C));
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            cin >> floor[i][j];
        }
    }

    int dir = 0; // Direção inicial (Norte)
    while (true) {
        int x = A, y = B;
        A += dx[dir];
        B += dy[dir];

        if (A < 0 || A >= L || B < 0 || B >= C || floor[A][B] == 0) {
            // Se o robô sai do mapa ou encontra um ladrilho branco, gira
            dir = (dir + 1) % 4;
            A = x;
            B = y;
        } else {
            // Se o robô encontra um ladrilho preto, continua em frente
            if (A != x || B != y) break;
        }
    }

    cout << A + 1 << " " << B + 1 << endl; // Convertendo para indices 1-based

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}