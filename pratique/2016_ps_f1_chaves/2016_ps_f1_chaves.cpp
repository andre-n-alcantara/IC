#include <iostream>
#include <string>
#include <stack>

int main() {
    int N;
    std::cin >> N;
    std::stack<char> pilha;

    for (int i = 0; i < N; i++) {
        std::string linha;
        std::getline(std::cin, linha);

        for (char c : linha) {
            if (c == '\\') {
                if (!pilha.empty() && pilha.top() == '\\') {
                    pilha.pop();
                } else {
                    pilha.push(c);
                }
            }
        }
    }

    std::cout << (pilha.empty() ? "S" : "N") << std::endl;
    return 0;
}