#include <ctime>
#include <iostream>

int main() {
    int N;
    std::cin >> N;
    int total = 1;
    for (int i = 0; i < N; i++) {
        int I;
        std::cin >> I;
        total = total * (I - 1);
    }
    std::cout << total << std::endl;
    
return 0;
}