/*
 * SoluÃ§Ã£o do problema 'Copa do Mundo' (OBI 2010 - NÃ­vel 1, Fase 1)
 *
 * MaurÃ­cio de Lemos Rodrigues Collares Neto (<mauricioc@gmail.com>)
 */

#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    /* A observaÃ§Ã£o importante para resolver este problema concisamente Ã© que
     * podemos processar cada linha do diagrama dado separadamente. Os vence-
     * dores da linha de Ã­ndice i estarÃ£o no array vencedores[i]. */
    vector<char> vencedores[5];

    /* A linha 0 contÃ©m todos os times. */
    for(char c = 'A'; c <= 'P'; c++)
	vencedores[0].push_back(c);

    /* E, para calcular a prÃ³xima linha, devemos pegar dois times consecutivos
     * da linha anterior, ler o resultado do jogo para saber quem ganhou, e co-
     * locar o vencedor na linha certa. */
    for(int l = 1; l < 5; l++) {

	/* Estamos pulando de 2 em 2, pois o primeiro jogo Ã© entre os times
	 * 0 e 1 da linha anterior, o segundo Ã© entre os times 2 e 3, e assim
	 * por diante. Se pularmos de 2 em 2, os jogos serÃ£o sempre entre os
	 * times j e j+1. */
	for(int j = 0; j < vencedores[l-1].size(); j += 2) {
	    int gols1, gols2;
	    scanf("%d %d", &gols1, &gols2);

	    if(gols1 > gols2)
		vencedores[l].push_back(vencedores[l-1][j]);
	    else
		vencedores[l].push_back(vencedores[l-1][j+1]);
	}
    }

    /* A quinta linha (de Ã­ndice 4) contÃ©m apenas um jogador: o vencedor. */
    printf("%c\n", vencedores[4][0]);
}

