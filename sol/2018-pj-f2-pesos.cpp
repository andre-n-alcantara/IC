#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool pode_subir(vector<int>& pesos) {
    int sum = 0;
    for (int peso : pesos) {
        sum += peso;
    }

    int avg = sum / pesos.size();

    for (int peso : pesos) {
        if (abs(peso - avg) > 8) {
            return false;
        }
    }

    return true;
}

int main() {
    std::clock_t startTime = std::clock();
    int N;
    cin >> N;

    vector<int> pesos(N);
    for (int i = 0; i < N; i++) {
        cin >> pesos[i];
    }

    sort(pesos.begin(), pesos.end());

    if (pode_subir(pesos)) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}