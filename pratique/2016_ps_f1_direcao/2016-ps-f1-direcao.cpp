#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<std::string, int> directions = {
        {"norte", 0}, {"leste", 90}, {"sul", 180}, {"oeste", 270}
    };

    std::string A, B;
    std::cin >> A >> B;

    int angleA = directions[A];
    int angleB = directions[B];

    int diff = std::abs(angleB - angleA);

    if (diff > 180) {
        diff = 360 - diff;
    }

    std::cout << diff << std::endl;

    return 0;
}