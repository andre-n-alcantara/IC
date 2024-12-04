
#include <iostream>

int main() {
    int N;
    std::cin >> N;

    if(N >= 90) std::cout << "A";
    else if(N >= 75) std::cout << "B";
    else if(N >= 60) std::cout << "C";
    else if(N >= 40) std::cout << "D";
    else std::cout << "E";

    return 0;
}
