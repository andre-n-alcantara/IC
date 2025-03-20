#include <ctime>
#include <iostream>

int main() {
    int V, T;
    std::cin >> V >> T;
    
    for (int i = 0; i < T; i++) {
        int A;
        std::cin >> A;
        V = std::max(0, std::min(100, V + A));
    }
    
    std::cout << V << std::endl;
    
    
return 0;
}