// Guilherme A. Pinto, OBI-2018, troca

#include <bits/stdc++.h>
using namespace std;

vector<int> frente, verso;
vector<bool> troca;
int N, T;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> N >> T;
  frente = vector<int>(N+2);
  verso = vector<int>(N+2);
  troca = vector<bool>(N+2);
  
  for( int i = 1; i <= N; i++ )
    cin >> frente[i];
  for( int i = 1; i <= N; i++ )
    cin >> verso[i];

  int I, J;  
  for( int k = 0; k < T; k++ ){
    cin >> I >> J;
    troca[I] = not troca[I];
    troca[J+1] = not troca[J+1];
  }

  bool f = true;
  for( int i = 1; i <= N; i++ ){
    if ( i > 1 ) cout << " ";
    if ( troca[i] ) f = not f;
    if ( f ) cout << frente[i];
    else cout << verso[i];
  }
  cout << endl;
  
  return 0;
}
