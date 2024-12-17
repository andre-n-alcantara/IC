#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N, M;
    cin >> N;
    vector<int> fila(N);
    for (int i = 0; i < N; i++) {
        cin >> fila[i];
    }
    cin >> M;
    vector<int> saida(M);
    for (int i = 0; i < M; i++) {
        cin >> saida[i];
    }
    for (int i = 0; i < M; i++) {
        fila.erase(remove(fila.begin(), fila.end(), saida[i]), fila.end());
    }
    for (int i = 0; i < N - M; i++) {
        cout << fila[i] << " ";
    }
    cout << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}