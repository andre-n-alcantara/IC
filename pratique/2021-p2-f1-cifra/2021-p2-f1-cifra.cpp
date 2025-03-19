#include <ctime>
#include <iostream>
#include <string>

std::string cifra(const std::string& palavra) {
  std::string cifrada = "";
  for (char c : palavra) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      cifrada += c;
    } else {
      char vogal;
      if (c == 'b' || c == 'c') vogal = 'a';
      else if (c == 'd') vogal = 'e';
      else if (c == 'f' || c == 'g') vogal = 'e';
      else if (c == 'h' || c == 'j') vogal = 'i';
      else if (c == 'k' || c == 'l') vogal = 'i';
      else if (c == 'm' || c == 'n') vogal = 'o';
      else if (c == 'p' || c == 'q' || c == 'r') vogal = 'o';
      else if (c == 's' || c == 't') vogal = 'u';
      else if (c == 'v' || c == 'x' || c == 'z') vogal = 'u';
      char proxima = c + 1;
      if (proxima > 'z') proxima = 'z';
      cifrada += c;
      cifrada += vogal;
      cifrada += proxima;
    }
  }
  return cifrada;
}

int main() {
    std::clock_t startTime = std::clock();
  std::string palavra;
  std::getline(std::cin, palavra);
  std::cout << cifra(palavra) << std::endl;
  
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}