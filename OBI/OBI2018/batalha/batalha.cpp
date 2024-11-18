// Guilherme A. Pinto, OBI-2018, batalha

#include <bits/stdc++.h>
using namespace std;

int main(){

  int A1,D1,A2,D2;
  
  cin >> A1;
  cin >> D1;
  cin >> A2;
  cin >> D2;

  // assume que deu empate
  int resultado = -1;
  
  // primeiro jogador vence
  if ( D1 == A2 and A1 != D2 ) resultado = 1;

  // segundo jogador vence
  if ( D2 == A1 and A2 != D1 ) resultado = 2;

  cout << resultado << endl;
  
  return 0;
}
