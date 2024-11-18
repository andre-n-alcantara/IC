/*
 * SoluÃ§Ã£o do problema 'SEDEX' (OBI 2010 - NÃ­vel JÃºnior, Fase 1)
 *
 * MaurÃ­cio de Lemos Rodrigues Collares Neto (<mauricioc@gmail.com>)
 */

#include <cstdio>

int main()
{
    int diametro;
    scanf("%d", &diametro);

    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);

    /* A menor caixa que contÃ©m uma esfera de diÃ¢metro d Ã© a caixa de lados
     * todos iguais a d, pois, neste caso, a esfera encosta perfeitamente nos
     * lados da caixa (o diÃ¢metro Ã© exatamente a distÃ¢ncia de um pÃ³lo a outro
     * da esfera; se a caixa toca os pÃ³los, ela tem que ter altura pelo menos
     * igual a d -- o mesmo raciocÃ­nio serve para os outros lados da caixa). 
     *
     * Precisamos entÃ£o verificar se todos os lados da caixa sÃ£o maiores ou
     * iguais ao diÃ¢metro da esfera para saber se a esfera cabe ou nÃ£o na 
     * caixa. */

    if(x >= diametro && y >= diametro && z >= diametro)
	printf("S\n");
    else
	printf("N\n");
}

