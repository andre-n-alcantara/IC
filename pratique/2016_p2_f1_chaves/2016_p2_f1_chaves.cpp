#include <ctime>
#include <iostream>
#include <stack>
#include <string>

int main() {
    int N;
    std::cin >> N;
    std::stack<char> stack;

    for (int i = 0; i < N; i++) {
        std::string line;
        std::getline(std::cin, line);

        for (char c : line) {
            if (c == '\\') {
                if (!stack.empty() && stack.top() == '\\') {
                    stack.pop();
                } else {
                    stack.push(c);
                }
            } else if (c == '{') {
                stack.push(c);
            } else if (c == '}') {
                if (!stack.empty() && stack.top() == '{') {
                    stack.pop();
                } else {
                    stack.push(c);
                }
            }
        }
    }

    std::cout << (stack.empty() ? "S" : "N") << std::endl;

    
return 0;
}