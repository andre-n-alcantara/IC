#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
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
    
return 0;
}