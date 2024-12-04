
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string horizontal, vertical;
    std::getline(std::cin, horizontal);
    std::getline(std::cin, vertical);

    int hv_idx = -1, vv_idx = -1;
    for (int i = horizontal.size() - 1; i >= 0; --i) {
        for (int j = vertical.size() - 1; j >= 0; --j) {
            if (horizontal[i] == vertical[j]) {
                hv_idx = i + 1;
                vv_idx = j + 1;
                break;
            }
        }
        if (hv_idx != -1) break;
    }

    std::cout << hv_idx << " " << vv_idx << std::endl;
    return 0;
}
