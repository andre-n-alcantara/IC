/*
 * SoluÃ§Ã£o do problema 'ReuniÃ£o' (OBI 2010 - NÃ­vel 2, Fase 1)
 *
 * MaurÃ­cio de Lemos Rodrigues Collares Neto (<mauricioc@gmail.com>)
 *
 * Este arquivo implementa a soluÃ§Ã£o usual para o problema de calcular o diÃ¢me-
 * tro de um grafo, que Ã© o nome tÃ©cnico dado ao que a questÃ£o pede.
 *
 * A idÃ©ia desta soluÃ§Ã£o Ã© computar, para cada um dos pares de cidades (u,v),
 * a menor distÃ¢ncia entre u e v usando o algoritmo de menor caminho de 
 * Floyd-Warshall. Tendo esta informaÃ§Ã£o, podemos tentar colocar o ponto de 
 * encontro dos caminhoneiros em cada uma das cidades, verificando qual delas 
 * faz com que a maior distÃ¢ncia percorrida pelos caminhoneiros seja a menor 
 * possÃ­vel.
 *
 * O tempo necessÃ¡rio para a execuÃ§Ã£o deste algoritmo Ã© dominado pelo algorit-
 * mo de Floyd-Warshall, e portanto a soluÃ§Ã£o executa em tempo proporcional a
 * n^3. 
 * 
 * O mesmo problema, com outra histÃ³ria, apareceu na prova da OBI de 2006, no 
 * mesmo nÃ­vel (programaÃ§Ã£o nÃ­vel 2, fase 1, questÃ£o 'Lanche na empresa').
 */

#include <cstdio>
#include <algorithm>

using namespace std;

/* O maior caminho possÃ­vel para um caminhoneiro passa por todas as cidades
 * (e portanto por n-1 estradas), cada uma com custo no mÃ¡ximo 100, donde
 * qualquer valor maior que 99*100 serve para esta constante. Usaremos um
 * valor maior por questÃ£o de costume. */
const int INF = 1000000000;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int dist[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dist[i][j] = INF;

    /* A menor distÃ¢ncia entre uma cidade e ela mesma Ã© zero. */
    for(int i = 0; i < n; i++)
        dist[i][i] = 0;

    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        /* Atualizando a menor distÃ¢ncia entre u e v. Vale lembrar que, como
         * pode haver mais de um par de estradas ligando o mesmo par de cidades,
         * tomar o mÃ­nimo entre o valor atual e o novo Ã© importante. */
        dist[u][v] = min(dist[u][v], w);

        /* NÃ£o esquecer de atualizar o custo de ir no sentido oposto, jÃ¡
         * que as estradas sÃ£o todas bidirecionais. */
        dist[v][u] = dist[u][v];
    }

    /* Este Ã© o algoritmo de Floyd-Warshall. Uma explicaÃ§Ã£o detalhada sobre ele
     * pode ser encontrada no Wikipedia, no seguinte endereÃ§o:
     * http://pt.wikipedia.org/wiki/Algoritmo_de_Floyd-Warshall
     *
     * Ao final de sua execuÃ§Ã£o, dist[u][v] Ã© a menor distÃ¢ncia que tem que ser
     * percorrida para ir de u a v, possivelmente usando cidades e estradas
     * intermediÃ¡rias. */
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j],
                                 dist[i][k] + dist[k][j]);

    int resp = INF;
    /* A i-Ã©sima iteraÃ§Ã£o deste loop corresponde a tomar a cidade i como
     * o ponto de encontro dos caminhoneiros. */     
    for(int i = 0; i < n; i++) {
        /* Calculamos a maior distÃ¢ncia que um caminhoneiro tem que percorrer 
           para chegar em i partindo de alguma outra cidade... */
        int max_dist = 0;
        for(int j = 0; j < n; j++)
            max_dist = max(max_dist, dist[i][j]);

        /* ...e verificamos se este valor Ã© melhor que o que jÃ¡ encontramos
         * atÃ© agora, atualizando a variÃ¡vel resp caso seja. */
        resp = min(resp, max_dist);
    }

    printf("%d\n", resp);
}

