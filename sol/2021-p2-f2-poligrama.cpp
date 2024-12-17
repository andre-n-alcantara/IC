#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool isAnagram(std::string a, std::string b) {
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    return a == b;
}

std::string findRoot(std::string word) {
    for (int len = 1; len <= word.size() / 2; ++len) {
        if (word.size() % len != 0) continue;
        std::string root = word.substr(0, len);
        bool isPoligram = true;
        for (int i = len; i < word.size(); i += len) {
            std::string sub = word.substr(i, len);
            if (!isAnagram(root, sub)) {
                isPoligram = false;
                break;
            }
        }
        if (isPoligram) return root;
    }
    return "*";
}

int main() {
    std::clock_t startTime = std::clock();
    int N;
    std::cin >> N;
    std::string word;
    std::cin >> word;
    std::cout << findRoot(word) << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}