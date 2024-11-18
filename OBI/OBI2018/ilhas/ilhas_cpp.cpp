// Guilherme A. Pinto, ilhas

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

// <custo,destino>
priority_queue<pii,vector<pii>,greater<pii>> q;

vector<vector<int>> adjG, costG;
vector<int> mark;

int N, M, maxPing, minPing, S;

void dijkstra(){
  q.push( { 0, S } );
  while( !q.empty() ){
    auto p = q.top(); q.pop();
    int d = p.first;
    int v = p.second;
    if ( !mark[v] ){
      mark[v] = 1;

      // guarda menor e maior ping vistos
      if ( v != S ){
	minPing = min(minPing, d);
	maxPing = max(maxPing, d);      
      }
      
      for ( int i = 0; i < (int)adjG[v].size(); i++ ) {	
	int u = adjG[v][i];
	int c = costG[v][i];
	if ( !mark[u] ) q.push( { d+c, u } );
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> N >> M;

  adjG = vector<vector<int>>(N);
  costG = vector<vector<int>>(N);

  for (int i = 0; i < M; i++) {
    int u, v, p;
    cin >> u >> v >> p; u--; v--;
    adjG[u].push_back(v); costG[u].push_back(p);
    adjG[v].push_back(u); costG[v].push_back(p);
  }

  cin >> S; S--;
  
  // Dijkstra
  minPing = numeric_limits<int>::max();
  maxPing = numeric_limits<int>::min();
  mark = vector<int>(N+1);
  dijkstra();
  
  cout << maxPing - minPing << endl;
  
  return 0;
}
