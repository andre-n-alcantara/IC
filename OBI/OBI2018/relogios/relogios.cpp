// Guilherme A. Pinto, OBI-2018, relogios

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int>> piii;

priority_queue<piii,vector<piii>,greater<piii>> q;

vector<vector<int>> sala,mark;

int dl[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

int L,C,K;

void transicao( int l, int c, int d, int a, int b ){
  int dn = sala[a][b];  
  if ( sala[l][c] == -1 ) { // posso esperar
    int dd = 1;
    if ( dn != -1 ) {
      if ( dn > d%K ) dd = dn-(d%K);
      else dd = (dn+K)-(d%K);
    }
    q.push( {d+dd,{a,b}} );
  } else { // nao posso esperar
    if ( dn == -1 or dn == (d+1)%K )
      q.push( {d+1,{a,b}} );
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> L >> C >> K;

  sala = vector<vector<int>>(L,vector<int>(C));
  mark = vector<vector<int>>(L,vector<int>(C));
  
  for( int i = 0; i < L; i++ )
    for( int j = 0; j < C; j++ )
      cin >> sala[i][j];

  // "Dijkstra"
  
  int res = -1;
  q.push( {0,{0,0}} );

  while ( !q.empty() ){
    auto v = q.top(); q.pop();

    int d = v.first;  
    int l = v.second.first;
    int c = v.second.second;

    if ( !mark[l][c] ){
      mark[l][c] = 1;

      // sala final
      if ( l == L-1 and c == C-1 ){
	res = d;
	break;
      }

      // transicoes a partir de [l,c]
      for ( int k = 0; k < 4; k++ ){
	int a = l+dl[k];
	int b = c+dc[k];
	if ( a >= 0 and a < L and b >= 0 and b < C )
	  if ( !mark[a][b] )
	    transicao( l, c, d, a, b );
      }
    }
  }
  
  cout << res << endl;  
  return 0;
}
