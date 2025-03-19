#include <iostream>
#include <string>
#include <algorithm>

std::pair<int, int> casamento(int A, int B) {
    std::string strA = std::to_string(A);
    std::string strB = std::to_string(B);

    int maxLen = std::max(strA.size(), strB.size());
    strA.insert(0, maxLen - strA.size(), '0');
    strB.insert(0, maxLen - strB.size(), '0');

    std::string resultA, resultB;
    for (int i = maxLen - 1; i >= 0; --i) {
        if (strA[i] < strB[i]) {
            resultB += strB[i];
        } else if (strA[i] > strB[i]) {
            resultA += strA[i];
        }
    }

    int retValA = resultA.empty() ? -1 : std::stoi(resultA);
    int retValB = resultB.empty() ? -1 : std::stoi(resultB);

    if (retValA > retValB) {
        std::swap(retValA, retValB);
    }

    return std::make_pair(retValA, retValB);
}

int main() {
    int A, B;
    std::cin >> A >> B;

    std::pair<int, int> result = casamento(A, B);

    std::cout << result.first << " " << result.second << std::endl;

    return 0;
}