/*
 * SoluÃ§Ã£o do problema 'Batalha naval' (OBI 2010 - NÃ­vel 2, Fase 1)
 *
 * MaurÃ­cio de Lemos Rodrigues Collares Neto (<mauricioc@gmail.com>)
 *
 * Esta soluÃ§Ã£o consiste em dar nÃºmeros aos navios e associar a cada cÃ©lula o
 * nÃºmero do navio correspondente a ela. Conta-se tambÃ©m quantas cÃ©lulas corres-
 * pondem a um dado navio. ApÃ³s disso, Ã© possÃ­vel identificar qual navio foi
 * atingido por um determinado tiro, e tambÃ©m Ã© possÃ­vel saber se um navio foi
 * completamente destruÃ­do (vendo se a quantidade de pedaÃ§os restantes do mesmo
 * Ã© igual a zero).
 */

#include <cstdio>

int qtd_navios, n, m;
int num_navio[100][100];
int pedacos_restantes[10000];

/* Este procedimento numera a cÃ©lula atual com o cÃ³digo do Ãºltimo navio
 * caso ela nÃ£o esteja numerada e tenta numerar todos os vizinhos recursiva-
 * mente. Ele Ã© chamado na funÃ§Ã£o main, e deve ser lido apenas depois da lei-
 * tura de tudo que antecede a chamada a ele na funÃ§Ã£o main. */
void numera_navios(int l, int c)
{
    /* Verifica se estamos fora do tabuleiro e pÃ¡ra caso sim. */
    if(l < 0 || l > n-1 || c < 0 || c > m-1)
       return;
    
    if(num_navio[l][c] != -2)
        return;

    num_navio[l][c] = qtd_navios;

    pedacos_restantes[qtd_navios]++;

    numera_navios(l-1, c);
    numera_navios(l, c-1);
    numera_navios(l+1, c);
    numera_navios(l, c+1);
}

int main()
{
    scanf("%d %d\n", &n, &m);

    /* Primeiro, ler a descriÃ§Ã£o do tabuleiro, guardando a informaÃ§Ã£o na matriz
     * num_navio. Os valores -1 e -2 significam 'Ã¡gua' e 'navio a ser numerado',
     * respectivamente. */
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char tmp;

            scanf("%c", &tmp);

            if(tmp == '.')
                num_navio[i][j] = -1;
            else
                num_navio[i][j] = -2;
        }
        scanf("\n");
    }

    /* Agora, vamos numerar todos os navios. Para cada quadrado nÃ£o ainda 
     * numerado (com valor -2), iremos dar um novo nÃºmero para ele e todos
     * os outros quadrados acessÃ­veis a partir dele. O contador de navios Ã©
     * entÃ£o incrementado.
     *
     * O nome tÃ©cnico deste procedimento Ã© 'flood fill'. Apesar de ter
     * usado recursÃ£o na implementaÃ§Ã£o abaixo por motivos didÃ¡ticos, 
     * recomenda-se aos competidores familiares com a estrutura de dados 
     * denominada 'pilha' que implementem a funÃ§Ã£o numera_navios usando-a,
     * pois esta Ã© mais apropriada do que a recursÃ£o para o flood fill. */
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(num_navio[i][j] == -2) {
                pedacos_restantes[qtd_navios] = 0;
                numera_navios(i, j);
                qtd_navios++;
            }
    
    int k, resp = 0;
    scanf("%d", &k);    

    /* Processa os tiros, um a um */
    for(int i = 0; i < k; i++) {
        int l, c;

        scanf("%d %d", &l, &c);

        /* Os tiros comeÃ§am do 1, logo precisamos subtrair. */
        l--; c--;

        int navio_atingido = num_navio[l][c];

        /* O tiro atingiu algum navio? */
        if(navio_atingido != -1) {
            /* Se sim, o navio tem um pedaÃ§o a menos, agora. Note que aqui
             * estamos explorando o fato de que nÃ£o Ã© possÃ­vel atirar num
             * lugar jÃ¡ destruÃ­do, jÃ¡ que nÃ£o Ã© possÃ­vel dar dois tiros no
             * mesmo lugar. */
            pedacos_restantes[navio_atingido]--;

            /* Se o navio nÃ£o tem mais nenhum pedaÃ§o restante, precisamos
             * incrementar a resposta, pois acabamos de destruir um navio
             * por completo */
            if(pedacos_restantes[navio_atingido] == 0) {
                resp++;
            }
        }
    }

    printf("%d\n", resp);
}

