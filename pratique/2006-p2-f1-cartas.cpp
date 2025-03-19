#include <ctime>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N;
    cin >> N;
    vector<int> compra(N);
    for (int i = 0; i < N; i++) {
        cin >> compra[i];
    }

    int rodadas = 0;
    queue<int> descarte;

    while (true) {
        int carta_proxima = rodadas + 1;
        while (true) {
            if (compra.empty()) {
                break;
            }
            int carta_atual = compra.back();
            compra.pop_back();
            descarte.push(carta_atual);
            if (carta_atual == carta_proxima) {
                carta_proxima++;
                break;
            }
        }
        rodadas++;

        if (compra.empty()) {
            break;
        }

        while (!descarte.empty()) {
            compra.push_back(descarte.front());
            descarte.pop();
        }
    }

    cout << rodadas << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}