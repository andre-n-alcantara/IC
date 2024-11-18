// OBI2020
// jogo dos pinos

#include <cstdio>

char tabuleiro[7][7];
int total = 0;
char descarte; // usado para descartar caractere final de linha

int main(void) {
  for (int lin = 0; lin < 7; lin++) {
    for (int col = 0; col < 7; col++)
      scanf("%c", &tabuleiro[lin][col]);
    scanf("%c", &descarte);
  }

  for( int lin = 0; lin < 7; lin++ ) 
    for( int col = 0; col < 7; col++ ) {
      if( lin+2 < 7 && tabuleiro[lin][col] == 'o' && tabuleiro[lin+1][col] == 'o' && tabuleiro[lin+2][col] == '.' )
	total++;
      if( lin-2 >= 0 && tabuleiro[lin][col] == 'o' && tabuleiro[lin-1][col] == 'o' && tabuleiro[lin-2][col] == '.' )
	total++;
      if( col+2 < 7 && tabuleiro[lin][col] == 'o' && tabuleiro[lin][col+1] == 'o' && tabuleiro[lin][col+2] == '.' )
	total++;
      if( col-2 >= 0 && tabuleiro[lin][col] == 'o' && tabuleiro[lin][col-1] == 'o' && tabuleiro[lin][col-2] == '.' )
	total++;
      } 
        
   printf("%d\n", total);

   return 0;
}
