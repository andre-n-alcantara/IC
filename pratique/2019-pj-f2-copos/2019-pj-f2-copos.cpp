#include <ctime>
#include <iostream>

char move(char pos, int type) {
    if (type == 1) {
        if (pos == 'A') return 'B';
        if (pos == 'B') return 'A';
        return pos;
    }
    if (type == 2) {
        if (pos == 'B') return 'C';
        if (pos == 'C') return 'B';
        return pos;
    }
    if (type == 3) {
        if (pos == 'A') return 'C';
        if (pos == 'C') return 'A';
        return pos;
    }
    return pos;
}

int main() {
    std::clock_t startTime = std::clock();
    int N;
    char pos;
    std::cin >> N >> pos;
    for (int i = 0; i < N; i++) {
        int type;
        std::cin >> type;
        pos = move(pos, type);
    }
    std::cout << pos << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}