/*
 * SoluÃ§Ã£o do problema 'GarÃ§om' (OBI 2010 - NÃ­vel JÃºnior, Fase 1)
 *
 * MaurÃ­cio de Lemos Rodrigues Collares Neto (<mauricioc@gmail.com>)
 */

#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);

    int copos_quebrados = 0;

    for(int i = 0; i < n; i++) {
	int num_latas, num_copos;
	scanf("%d %d", &num_latas, &num_copos);

	/* Como o problema descreve, o garÃ§om quebra todos os copos da bandeja
	 * se houver mais latas que copos na bandeja. Se isso ocorrer, modifi-
	 * camos a variÃ¡vel copos_quebrados apropriadamente. */
	if(num_latas > num_copos)
	    copos_quebrados += num_copos;
    }

    printf("%d\n", copos_quebrados);
}

