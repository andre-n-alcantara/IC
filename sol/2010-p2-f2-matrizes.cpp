#include <ctime>
#include <iostream>

using namespace std;

const int MOD = 1000000007;

long long mul(long long a, long long b) {
    return (a * b) % MOD;
}

int main() {
    std::clock_t startTime = std::clock();
    int N, P, Q, R, S, X, Y, I, J;
    cin >> N >> P >> Q >> R >> S >> X >> Y >> I >> J;

    long long C = 0;
    for (int k = 1; k <= N; k++) {
        C = (C + mul((P * I + Q * k) % X, (R * k + S * J) % Y)) % MOD;
    }

    cout << C << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}