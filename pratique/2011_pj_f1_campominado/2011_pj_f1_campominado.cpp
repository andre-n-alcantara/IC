#include <ctime>
#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int mines[N];
    for (int i = 0; i < N; i++) {
        std::cin >> mines[i];
    }

    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int j = i - 1; j <= i + 1; j++) {
            if (j >= 0 && j < N && mines[j] == 1) {
                count++;
            }
        }
        if (mines[i] == 0) {
            count--;
        }
        std::cout << count << std::endl;
    }

    
return 0;
}