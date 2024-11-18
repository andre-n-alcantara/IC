// Guilherme A. Pinto, capsulas, busca binaria

#include <bits/stdc++.h>
using namespace std;

#define MAX_DIAS 100000000

vector<int> ciclos;
int N,F;

int fortuna( int dia ){
  int ret = 0;
  for ( auto c: ciclos )
    ret += (dia/c);
  return ret;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> N >> F;
  ciclos = vector<int>(N);

  for( int i = 0; i < N; i++ )
    cin >> ciclos[i];

  int lo,hi,mid;

  lo = 1;
  hi = MAX_DIAS;

  // busca binaria
  while ( lo < hi ){
    mid = lo+(hi-lo)/2;
    if ( fortuna( mid ) < F ) lo = mid+1;
    else hi = mid;    
  }
  
  // lo = hi = resposta
  cout << lo << endl;
  
  return 0;
}
