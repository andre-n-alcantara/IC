#include <iostream>

int main() {
    int t1, t2, t3;
    std::cin >> t1 >> t2 >> t3;

    if (t1 < t2 && t1 < t3) {
        std::cout << "1\n";
        if (t2 < t3) {
            std::cout << "2\n3\n";
        } else {
            std::cout << "3\n2\n";
        }
    } else if (t2 < t1 && t2 < t3) {
        std::cout << "2\n";
        if (t1 < t3) {
            std::cout << "1\n3\n";
        } else {
            std::cout << "3\n1\n";
        }
    } else {
        std::cout << "3\n";
        if (t1 < t2) {
            std::cout << "1\n2\n";
        } else {
            std::cout << "2\n1\n";
        }
    }

    return 0;
}