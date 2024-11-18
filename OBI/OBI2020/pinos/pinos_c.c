// OBI2020
// jogo dos pinos

#include <stdio.h>

char tab[7][9]; 
int total = 0;

int main(void) {
  for (int lin = 0; lin < 7; lin++) {
    fgets(&tab[lin][0],9,stdin);
    // precisa ler 7 caracteres + final de linha, fgets coloca 0 no final da "string"
  }

  
  for (int lin = 0; lin < 7; lin++) 
    for (int col = 0; col < 7; col++) {
      if (lin+2 < 7 && tab[lin][col] == 'o' && tab[lin+1][col] == 'o' && tab[lin+2][col] == '.')
	total++;
      if (lin-2 >= 0 && tab[lin][col] == 'o' && tab[lin-1][col] == 'o' && tab[lin-2][col] == '.')
	total++;
      if (col+2 < 7 && tab[lin][col] == 'o' && tab[lin][col+1] == 'o' && tab[lin][col+2] == '.')
	total++;
      if (col-2 >= 0 && tab[lin][col] == 'o' && tab[lin][col-1] == 'o' && tab[lin][col-2] == '.')
	total++;
      } 
        
   printf( "%d\n", total);

   return 0;
}
