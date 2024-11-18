#include <iostream>
using namespace std;

int main(){
  int D;
  
  cin >> D;

  int pontuacao;

  pontuacao = 3;
  if ( D <= 1400 ) pontuacao = 2;
  if ( D <= 800 ) pontuacao = 1;

  cout << pontuacao << endl;
  
  return 0;
}
