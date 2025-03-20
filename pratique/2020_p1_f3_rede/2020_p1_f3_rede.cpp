#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> repos(N);
    for (int i = 0; i < N; i++) {
        std::cin >> repos[i];
    }
    std::sort(repos.begin(), repos.end());
    int infl = 0;
    for (int i = 0; i < N; i++) {
        if (repos[i] >= i + 1) {
            infl = i + 1;
        } else {
            break;
        }
    }
    std::cout << infl << std::endl;
    
return 0;
}