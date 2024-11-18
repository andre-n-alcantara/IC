/*
 * SoluÃ§Ã£o 1 do problema 'Cometa' (OBI 2010 - NÃ­vel 2, Fase 1) 
 *
 * MaurÃ­cio de Lemos Rodrigues Collares Neto (<mauricioc@gmail.com>)
 */

#include <cstdio>

int main()
{
    /* O cometa passa em 1986, 1986 + 76, 1986 + 2*76, 1986 + 3*76... Subtraindo
     * 1986 desses nÃºmeros, vemos que todos eles sÃ£o todos os mÃºltiplos nÃ£o-ne-
     * gativos de 76. 
     *
     * Podemos entÃ£o ir verificando os anos seguintes ao ano da entrada, vendo
     * se algum se encaixa na descriÃ§Ã£o acima. Encontraremos um ano vÃ¡lido em
     * no mÃ¡ximo 76 tentativas.
     */

    int x;
    scanf("%d", &x);

    for(int i = x + 1; ; i++)
        if((i - 1986) % 76 == 0) {
            printf("%d\n", i);
            break;
        }
}

