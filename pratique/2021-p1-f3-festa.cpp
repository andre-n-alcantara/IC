#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N, M;
    cin >> N >> M;

    vector<bool> lista(N + 1, true);

    for (int i = 0; i < M; i++) {
        int Ti;
        cin >> Ti;
        for (int j = Ti; j <= N; j += Ti) {
            lista[j] = false;
        }
    }

    int cont = 0;
    for (int i = 1; i <= N; i++) {
        if (lista[i]) {
            cout << i << endl;
            cont++;
            if (cont == 10000) break;
        }
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}