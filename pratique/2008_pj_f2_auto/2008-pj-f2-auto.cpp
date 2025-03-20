#include <ctime>
#include <iostream>
#include <string>

int main() {
    int C;
    std::string highway;
    std::cin >> C;
    std::cin >> highway;

    int panels = 0;
    for (char c : highway) {
        switch (c) {
            case 'P':
                panels += 2;
                break;
            case 'C':
                panels += 2;
                break;
            case 'A':
                panels += 1;
                break;
            case 'D':
                panels += 0;
                break;
        }
    }

    std::cout << panels << std::endl;

    
return 0;
}