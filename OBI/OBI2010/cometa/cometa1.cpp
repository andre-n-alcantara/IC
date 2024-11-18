/*
 * SoluÃ§Ã£o 2 do problema 'Cometa' (OBI 2010 - NÃ­vel 2, Fase 1)
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
     * Precisamos entÃ£o calcular a prÃ³xima vez que o cometa passa, ou seja,
     * o prÃ³ximo nÃºmero y > x tal que (y - 1986) Ã© um mÃºltiplo nÃ£o-negativo de 
     * 76. Ser um mÃºltiplo de 76 significa que (y - 1986) % 76 = 0. Agora, se
     * (x - 1986) % 76 = m, entÃ£o (x - 1986 + (76 - m)) % 76 = (m + 76 - m) % 76
     * = 76 % 76 = 0, done podemos apenas somar (76 - m) Ã  entrada para obter um
     * ano onde o cometa passa.

     * Ã‰ claro que o ano obtido acima Ã© o prÃ³ximo ano que o cometa passarÃ¡ 
     * novamente se m != 0, pois nenhum ano menor Ã© tal que (y - 1986) Ã© mÃºl-
     * tiplo de 76. Mas o procedimento tambÃ©m funciona para o caso em que m 
     * Ã© zero, como pode-se verificar separadamente. */

    int x;
    scanf("%d", &x);

    int m = (x - 1986) % 76;
    printf("%d\n", x + (76 - m));
}

