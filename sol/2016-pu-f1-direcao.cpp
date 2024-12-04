#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<std::string, int> directions = {{"norte", 0}, {"leste", 90}, {"sul", 180}, {"oeste", 270}};
    std::string A, B;
    std::cin >> A >> B;
    int diff = abs(directions[B] - directions[A]);
    if (diff > 180) {
        diff = 360 - diff;
    }
    std::cout << diff << std::endl;
    return 0;
}