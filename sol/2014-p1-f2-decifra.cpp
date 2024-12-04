#include <iostream>
#include <string>

int main() {
    std::string permutation, encryptedText;
    std::getline(std::cin, permutation);
    std::getline(std::cin, encryptedText);

    for (char& c : encryptedText) {
        c = permutation[c - 'a'];
    }

    std::cout << encryptedText << std::endl;

    return 0;
}