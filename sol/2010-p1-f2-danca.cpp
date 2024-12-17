#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N, E;
    cin >> N >> E;
    vector<int> direcao(N + 1, 0);
    vector<int> posicao(N + 1, 0);
    for (int i = 0; i < E; i++) {
        int V, D;
        cin >> V >> D;
        direcao[V] = D;
        posicao[V] = 1;
    }
    int tempo = 0;
    bool changed;
    do {
        changed = false;
        for (int i = 1; i <= N; i++) {
            if (posicao[i] == 1) {
                int next = (i + direcao[i] > N) ? i + direcao[i] - N : i + direcao[i];
                if (posicao[next] == 1) {
                    direcao[i] *= -1;
                    direcao[next] *= -1;
                    changed = true;
                } else if (abs(next - i) == 1) {
                    direcao[i] *= -1;
                    changed = true;
                } else {
                    posicao[next] = 1;
                    posicao[i] = 0;
                    changed = true;
                }
            }
        }
        tempo++;
    } while (changed);
    cout << tempo << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}