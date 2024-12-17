#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N, K;
    cin >> N >> K;
    vector<int> primes(K);
    for (int i = 0; i < K; i++)
        cin >> primes[i];

    int count = N;
    for (int i = 2; i * i <= N; i++) {
        bool isPrime = true;
        for (int j = 0; j < K; j++) {
            if (primes[j] == i) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) continue;
        for (int j = i; j <= N; j += i)
            count--;
    }

    cout << count << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}