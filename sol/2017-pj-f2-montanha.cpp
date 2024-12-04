
#include <iostream>

int main() {
    int N;
    std::cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    bool multi_pico = false;
    for (int i = 1; i < N - 1; i++) {
        if (A[i-1] > A[i] && A[i] < A[i+1]) {
            multi_pico = true;
            break;
        }
    }
    if (multi_pico) {
        std::cout << "S\n";
    } else {
        std::cout << "N\n";
    }
    return 0;
}
