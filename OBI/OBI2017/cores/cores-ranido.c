// r. anido
// problema cores, OBI2017

#include <stdio.h>

#define MAX 100

int n,m;
int caminhos[MAX][MAX];         // vamos manter o grafo dos caminhos em uma matriz, porque é simples e o
                                // número de castelos é pequeno (<=100)
int cores[MAX];                 // cor de cada castelo
int visitado[MAX];              // usado para encontrar caminho entre castelo x e castelo y
int caminho[MAX];               // contém castelos no caminho entre castelo x e castelo y
int i_caminho;                  // número de castelos presentes no vetor caminho

// procedimento recursivo para colorir castelos de i a j com cor
void pinta(int i, int j, int cor) {
  int k;

  if (i==j) { // chegou ao castelo j, vamos pintar todos no caminho até aqui com cor
    for (k=0; k<i_caminho; k++) {
      cores[caminho[k]]=cor;
    }
    cores[i]=cor;
    return;
  }
  visitado[i]=1;                 // marca como visitado, não visita mais nesta ordem de pintura
  caminho[i_caminho++]=i;        // coloca no caminho corrente
  for (k=0; k<n; k++) {
    if (caminhos[i][k]==1 && visitado[k]==0)
      pinta(k,j,cor);
  }
  i_caminho--;                   // retira castelo i do caminho, não chegou ao castelo j usando i
}

int main(void) {
  int i,j,x,y,c;
  
  scanf("%d%d",&n,&m);          // lê valor de N
  // inicializa cores dos castelos
  for (i=0; i<n; i++) 
    cores[i]=0;
  // inicializa matriz de conexões
  for (i=0; i<n; i++) 
    for (j=0; j<n; j++) 
      caminhos[i][j]=0;
  // le conexoes
  for (i=0; i<n-1; i++) {
    scanf("%d%d",&x,&y); 
    caminhos[x-1][y-1]=1;
    caminhos[y-1][x-1]=1;
  }
  // lê as ordens de colorir
  for (i=0; i<m; i++) {
    scanf("%d%d%d",&x,&y,&c);
    // cumpre a ordem (colore os castelos de x a y)
    for (j=0; j<n; j++) 
      visitado[j]=0;            // marca todos os castelos como não visitados
    i_caminho=0;                // não tem castelo no caminho ainda
    pinta(x-1,y-1,c);           // encontra caminho do castelo x ao castelo y e pinta castelos
  }
  // imprime o resultado
  for (i=0; i<n-1; i++)
    printf("%d ",cores[i]);      
  printf("%d\n",cores[n-1]);      
  return 0;
}
