#include <ctime>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Carrinho {
    int id;
    int ultimoPosto;
    int proximoPosto;
};

bool operator<(const Carrinho& a, const Carrinho& b) {
    if (a.ultimoPosto != b.ultimoPosto) {
        return a.ultimoPosto < b.ultimoPosto;
    } else {
        return a.id < b.id;
    }
}

int main() {
    std::clock_t startTime = std::clock();
    int K, N, M;
    cin >> K >> N >> M;

    map<int, Carrinho> carrinhos;
    for (int i = 1; i <= N; i++) {
        carrinhos[i] = {i, 0, 1};
    }

    priority_queue<Carrinho> pq;

    for (int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        if (carrinhos[X].proximoPosto == Y) {
            carrinhos[X].ultimoPosto = Y;
            carrinhos[X].proximoPosto = (Y % K) + 1;
            pq.push(carrinhos[X]);
        }
    }

    vector<int> resultado;
    while (!pq.empty()) {
        resultado.push_back(pq.top().id);
        pq.pop();
    }

    for (int i = resultado.size() - 1; i >= 0; i--) {
        cout << resultado[i] << " ";
    }
    cout << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}