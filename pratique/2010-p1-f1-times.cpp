#include <ctime>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>

struct Aluno {
    std::string nome;
    int habilidade;
};

bool operator<(const Aluno& a, const Aluno& b) {
    return a.habilidade > b.habilidade;
}

int main() {
    std::clock_t startTime = std::clock();
    int N, T;
    std::cin >> N >> T;

    std::priority_queue<Aluno> fila;
    std::map<std::string, int> mapa;

    for (int i = 0; i < N; i++) {
        Aluno aluno;
        std::cin >> aluno.nome >> aluno.habilidade;
        fila.push(aluno);
    }

    std::vector<std::vector<std::string>> times(T);

    for (int i = 0; i < N; i++) {
        Aluno aluno = fila.top();
        fila.pop();
        times[i % T].push_back(aluno.nome);
    }

    for (int i = 0; i < T; i++) {
        std::cout << "Time " << i + 1 << std::endl;
        std::vector<std::string> time = times[i];
        std::sort(time.begin(), time.end());
        for (std::string aluno : time) {
            std::cout << aluno << std::endl;
        }
        std::cout << std::endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}