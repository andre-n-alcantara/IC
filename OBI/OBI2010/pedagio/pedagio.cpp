/*
 * SoluÃ§Ã£o do problema 'PedÃ¡gio' (OBI 2010 - NÃ­vel 1, Fase 1)
 *
 * MaurÃ­cio de Lemos Rodrigues Collares Neto (<mauricioc@gmail.com>)
 */

#include <cstdio>

int main()
{
    int l, d, k, p;
    scanf("%d %d", &l, &d);
    scanf("%d %d", &k, &p);

    int resposta = 0;
    
    /* O primeiro custo que temos Ã© um custo de k reais por quilÃ´metro 
     * percorrido. Como tempos l quilÃ´metros, o custo total com a gasolina
     * Ã© de k * l reais. 
     *
     * Este valor pode ser, no mÃ¡ximo, 10^4 * 10^4, e portanto podemos usar
     * uma variÃ¡vel do tipo int. */
    resposta += k * l;

    /* O outro custo Ã© o custo dos pedÃ¡gios. Precisamos entÃ£o saber quantos
     * pedÃ¡gios estÃ£o presentes numa pista de comprimento l que tem pedÃ¡gios
     * espaÃ§ados de d quilÃ´metros. Mas, vejamos um exemplo. Se l = 21 e d = 5,
     * a pista se parece com isso:
     *
     * ____P____P____P____P_
     * 123451234512345123451
     *
     * Note que podemos pensar que estamos dividindo a pista igualmente em pe-
     * daÃ§os de 5km e colocando um pedÃ¡gio em cada parte dividida, ignorando
     * o resto. EntÃ£o, o nÃºmero de pedÃ¡gios Ã© uma simples divisÃ£o. No exemplo,
     * se dividirmos 21 por 5, obtemos 4,25, que significa que temos 4 pedÃ¡gios
     * e um "pedaÃ§o de pista" (correspondente a 0,25 do comprimento normal da
     * pista de um pedÃ¡gio), que deve ser ignorado segundo o problema. Como a
     * divisÃ£o inteira do C++ automaticamente ignora a parte fracionÃ¡ria de 
     * um nÃºmero, temos (l/d) pedaÃ§os, cada um custando p reais, e portanto
     * o custo total Ã© de (l/d) * p reais.
     *
     * O valor acima tambÃ©m Ã©, no mÃ¡ximo, 10^4 * 10^4, donde resposta Ã© no
     * mÃ¡ximo 2 * 10^8 e portanto ainda pode ser representada por um int. */
    resposta += (l/d) * p;

    printf("%d\n", resposta);
}

