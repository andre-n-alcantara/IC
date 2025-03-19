#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N, M;
    cin >> N >> M;
    vector<int> memoria(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int tipo, addr, valor;
        cin >> tipo >> addr >> valor;

        if (tipo == 1) { // FRENTE
            for (int j = addr; j <= N && valor > 0; j++) {
                memoria[j] += valor--;
            }
        } else if (tipo == 2) { // TRÁS
            for (int j = addr; j >= 1 && valor > 0; j--) {
                memoria[j] += valor--;
            }
        } else if (tipo == 3) { // IMPRIME
            cout << memoria[addr] << endl;
        }
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}