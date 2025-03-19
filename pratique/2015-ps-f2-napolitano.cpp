#include <iostream>
#include <string>
#include <map>

std::map<char, int> values = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

int napolitano(std::string s) {
    int result = 0;
    for (int i = 0; i < s.size(); ++i) {
        int current = values[s[i]];
        if (i + 1 < s.size()) {
            int next = values[s[i + 1]];
            if (current < next) {
                current = -current;
            }
        }
        result += current;
    }
    return result;
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << napolitano(s) << std::endl;
    return 0;
}