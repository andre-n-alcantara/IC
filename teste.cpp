#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int area1, area2, area3;
    std::string color1, color2, color3;

    // Leia as áreas das paredes e as cores
    std::cin >> area1 >> area2 >> area3;
    std::cin >> color1 >> color2 >> color3;

    // Ordene as áreas das paredes em ordem crescente
    int areas[] = {area1, area2, area3};
    std::sort(areas, areas + 3);

    // Associe as cores às áreas das paredes ordenadas
    std::string colors[3];
    if (area1 == areas[0]) colors[0] = color1;
    if (area1 == areas[1]) colors[1] = color1;
    if (area1 == areas[2]) colors[2] = color1;

    if (area2 == areas[0]) colors[0] = color2;
    if (area2 == areas[1]) colors[1] = color2;
    if (area2 == areas[2]) colors[2] = color2;

    if (area3 == areas[0]) colors[0] = color3;
    if (area3 == areas[1]) colors[1] = color3;
    if (area3 == areas[2]) colors[2] = color3;

    // Imprima a cor correspondente à parede intermediária
    std::cout << colors[1] << std::endl;

    return 0;
}