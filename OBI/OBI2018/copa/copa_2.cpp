// Guilherme A. Pinto, OBI-2018, campeonato

#include <bits/stdc++.h>
using namespace std;

string fase[4] {"final", "semifinal", "quartas", "oitavas" };
int A, B;

string chave( int f, int lo, int hi ){
  // base
  if ( f == 3 ) return fase[f];
  // recursao
  int mid = lo+(hi-lo)/2;
  if ( A <= mid and B > mid ) return fase[f];
  if ( B <= mid ) return chave( f+1, lo, mid );
  return chave( f+1, mid+1, hi );
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int i,j;
  cin >> A;
  cin >> B;

  if ( A > B ) swap( A, B );

  cout << chave( 0, 1, 16 ) << endl;
  
  return 0;
}
