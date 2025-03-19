#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::pair<int, int> casamento(int A, int B) {
    std::string strA = std::to_string(A);
    std::string strB = std::to_string(B);

    int maxSize = std::max(strA.size(), strB.size());
    strA.insert(0, maxSize - strA.size(), '0');
    strB.insert(0, maxSize - strB.size(), '0');

    std::string newA, newB;
    for (int i = maxSize - 1; i >= 0; i--) {
        if (strA[i] < strB[i]) {
            newA += strA[i];
        } else if (strA[i] > strB[i]) {
            newB += strB[i];
        }
    }

    int a = newA.empty() ? -1 : std::stoi(newA);
    int b = newB.empty() ? -1 : std::stoi(newB);

    if (a > b) std::swap(a, b);

    return std::make_pair(a, b);
}

int main() {
    int A, B;
    std::cin >> A >> B;

    std::pair<int, int> result = casamento(A, B);

    std::cout << result.first << " " << result.second << std::endl;

    return 0;
}