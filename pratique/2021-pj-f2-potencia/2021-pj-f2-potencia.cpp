#include <ctime>
#include <iostream>

int main() {
    int n;
    std::cin >> n;

    long long sum = 0;
    for(int i = 0; i < n; i++) {
        int t;
        std::cin >> t;
        int base = t / 10;
        int exp = t % 10;
        long long result = 1;
        for(int j = 0; j < exp; j++) {
            result *= base;
        }
        sum += result;
    }

    std::cout << sum << std::endl;

    
return 0;
}