#include <bits/stdc++.h>
using namespace std;

set<int> album;

int main(){
  int N, M;
  
  cin >> N >> M;

  for ( int i = 0; i < M; i++ ){
    int fig;
    cin >> fig;
    album.insert( fig );
  }

  cout << N - album.size() << endl;
    
  return 0;
}
