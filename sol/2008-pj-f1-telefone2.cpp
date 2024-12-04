#include <iostream>
#include <string>

int main() {
    std::string phone;
    std::cin >> phone;

    std::string mapping = "222333444555666777788899";
    for (char &c : phone) {
        if (c == '-') continue;
        c = toupper(c);
        c = mapping[c - 'A' - 19];
    }

    std::cout << phone << std::endl;

    return 0;
}