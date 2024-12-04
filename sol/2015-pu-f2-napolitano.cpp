#include <iostream>
#include <string>
#include <map>

std::map<char, int> values = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

int napoletano(std::string s) {
    int result = 0;
    for (int i = 0; i < s.size(); ++i) {
        int currentValue = values[s[i]];
        if (i < s.size() - 1) {
            int nextValue = values[s[i + 1]];
            if (currentValue < nextValue) {
                currentValue = nextValue - currentValue;
            }
        }
        result += currentValue;
    }
    return result;
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << napoletano(s) << std::endl;
    return 0;
}