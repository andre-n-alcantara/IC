#include <iostream>
#include <set>

int main() {
    int N;
    std::cin >> N;

    std::set<int> alunos;

    for (int i = 0; i < N; i++) {
        int Vi;
        std::cin >> Vi;
        alunos.insert(Vi);
    }

    std::cout << alunos.size() << std::endl;

    return 0;
}