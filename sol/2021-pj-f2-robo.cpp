
#include <iostream>

int main() {
    int N, C, S;
    std::cin >> N >> C >> S;

    int currentStation = 1;
    int count = 0;

    for (int i = 0; i < C; i++) {
        int command;
        std::cin >> command;

        if (command == 1) {
            currentStation = (currentStation % N) + 1;
        } else {
            currentStation = (currentStation - 2 + N) % N + 1;
        }

        if (currentStation == S) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}
