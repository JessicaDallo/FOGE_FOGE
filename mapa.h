#include <stdio.h>
#include <stdlib.h>

struct mapa
{
	char **matriz;
	int linhas;
	int colunas;
};
typedef struct mapa MAPA;

struct posicao
{
	int x;
	int y;
	int proxx;
	int proxy;
};
typedef struct posicao POSICAO;

void freemapa(MAPA *m);
void initmapa(MAPA *m);
void lemapa(MAPA *m);
void imprimemapa(MAPA *m);
void encontramapa(MAPA *m, POSICAO *p, char c);
