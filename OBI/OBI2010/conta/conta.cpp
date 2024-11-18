/*
 * SoluÃ§Ã£o do problema 'Conta de Ã¡gua' (OBI 2010 - NÃ­vel 1, Fase 1)
 *
 * MaurÃ­cio de Lemos Rodrigues Collares Neto (<mauricioc@gmail.com>)
 */

#include <cstdio>

int main()
{
    /* Todo consumidor Ã© obrigado a pagar os 7 reais de assinatura. */
    int preco = 7, consumo;
    scanf("%d", &consumo);

    /* A idÃ©ia das condicionais abaixo Ã© que podemos pagar "o final" da
     * conta sem alterar o preÃ§o do comeÃ§o. Por exemplo, se a conta Ã© de
     * 150 m^3, podemos pagar o consumo de 101 m^3 a 150 m^3 e pensar que 
     * ainda temos uma conta de 100 m^3 a pagar. 
     *
     * Note que temos uma condicional repetida vÃ¡rias vezes, com apenas 
     * alguns nÃºmeros mÃ¡gicos mudando. Isto sugere a substituiÃ§Ã£o das repe-
     * tiÃ§Ãµes por um loop e um vetor com os nÃºmeros mÃ¡gicos, e fica como
     * exercÃ­cio para o leitor. */

    if(consumo > 100) {
	preco += 5 * (consumo - 100);
	consumo = 100;
    }

    if(consumo > 30) {
	preco += 2 * (consumo - 30);
	consumo = 30;
    }

    if(consumo > 10)
	preco += consumo - 10;

    printf("%d\n", preco);
}

