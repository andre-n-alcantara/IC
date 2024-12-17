#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Tenda {
    int x, y;
};

bool compareTendas(const Tenda& a, const Tenda& b) {
    return a.x * a.x + a.y * a.y > b.x * b.x + b.y * b.y;
}

int main() {
    std::clock_t startTime = std::clock();
    int N;
    cin >> N;

    vector<Tenda> tendas(N);
    for (int i = 0; i < N; i++) {
        cin >> tendas[i].x >> tendas[i].y;
    }

    sort(tendas.begin(), tendas.end(), compareTendas);

    int guloseimas = 0;
    for (int i = 0; i < N; i++) {
        guloseimas += i % 2 + 1;
    }

    cout << guloseimas << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}