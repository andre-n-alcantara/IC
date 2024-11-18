/*
 * SoluÃ§Ã£o do problema 'Times' (OBI 2010 - NÃ­vel 1, Fase 1)
 *
 * MaurÃ­cio de Lemos Rodrigues Collares Neto (<mauricioc@gmail.com>)
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<pair<int, string> > jogadores;
    for(int i = 0; i < n; i++) {
	string nome; int nivel;
	cin >> nome >> nivel;

	jogadores.push_back(make_pair(nivel, nome));
    }

    /* O sort do C++ ordena pares de acordo com a primeira coordenada e,
     * em caso de empate, de acordo com a segunda. Como o problema garante
     * que nÃ£o haverÃ£o empates na primeira coordenada (o nÃ­vel), isto ordena
     * os jogadores do menos habilidoso ao mais habilidoso... */
    sort(jogadores.begin(), jogadores.end());

    /* ...mas precisamos da ordem contrÃ¡ria. */
    reverse(jogadores.begin(), jogadores.end());

    /* Agora Ã© sÃ³ distribuir os jogadores nos times, que serÃ£o indexados por
     * 0 por conveniÃªncia. A funÃ§Ã£o mÃ³dulo determina em qual time o jogador
     * de nÃºmero i ira cair (i % k), pois esta funÃ§Ã£o basicamente remove "roda-
     * das completas" do nÃºmero i: Os valores de (i % k) quando i muda sÃ£o:
     *
     *   i 0, 1, 2, ..., k-1, k, k+1, k+2, ..., 
     * i%k 0, 1, 2, ..., k-1, 0,   1,   2, ..., 
     *
     * que corresponde a colocar um jogador no time de Ã­ndice 0, depois no
     * time de Ã­ndice 1, depois no time de Ã­ndice 2, ..., depois no time de
     * Ã­ndice k-1, depois no time de Ã­ndice 0... */

    vector<string> times[k];
    for(int i = 0; i < n; i++)
	times[i % k].push_back(jogadores[i].second);
    
    /* Agora basta imprimir os times um a um. */
    for(int i = 0; i < k; i++)
    {
	cout << "Time " << i + 1 << endl;

	/* Mas queremos os jogadores em ordem alfabÃ©tica, logo precisamos
	 * ordenar novamente. */
	sort(times[i].begin(), times[i].end());

	for(int j = 0; j < times[i].size(); j++)
	    cout << times[i][j] << endl;

	cout << endl;
    }
}

