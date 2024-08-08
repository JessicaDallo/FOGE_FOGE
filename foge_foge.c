#include "foge_foge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

int acabou() 
{
	if (m.matriz[heroi.proxx][heroi.proxy] == 'A')
	{
		m.matriz[heroi.proxx][heroi.proxy] = '@';
		m.matriz[heroi.x][heroi.y] = '.';
		printf("  _____        _____            ____  ______ _   _  _____ \n");
		printf(" |  __ \\ /\\   |  __ \\     /\\   |  _ \\|  ____| \\ | |/ ____|\n");
		printf(" | |__) /  \\  | |__) |   /  \\  | |_) | |__  |  \\| | (___  \n");
		printf(" |  ___/ /\\ \\ |  _  /   / /\\ \\ |  _ <|  __| | . ` |\\___ \\ \n");
		printf(" | |  / ____ \\| | \\ \\  / ____ \\| |_) | |____| |\\  |____) |\n");
		printf(" |_| /_/    \\_\\_|  \\_\\/_/    \\_\\____/|______|_| \\_|_____/ \n");
		exit (EXIT_SUCCESS);
	}	
	return 0;
}

void move(char direcao)
{
	if(direcao != 'a' && direcao != 'w' && direcao != 's' && direcao != 'd')
		return ;
	heroi.proxx = heroi.x;
	heroi.proxy = heroi.y;
	
	switch(direcao)
	{
		case 'a':
			heroi.proxy--;
			break;
		case 'w':
			heroi.proxx--;
			break;
		case 's':
			heroi.proxx++;
			break;
		case 'd':
			heroi.proxy++;
			break;
	}
	if (heroi.proxx >= m.linhas || heroi.proxy >= m.colunas)
		return ;
	if (m.matriz[heroi.proxx][heroi.proxy] != '.' && m.matriz[heroi.proxx][heroi.proxy] != 'A')
		return ;
	if(m.matriz[heroi.proxx][heroi.proxy] == 'A')
		acabou(heroi.proxx, heroi.proxy);
	m.matriz[heroi.proxx][heroi.proxy] = '@';
	m.matriz[heroi.x][heroi.y] = '.';
	heroi.x = heroi.proxx;
	heroi.y = heroi.proxy;
}

int main()
{
	lemapa(&m);
	encontramapa(&m, &heroi, '@');
	do
	{
		imprimemapa(&m);
		char comando;
		scanf(" %c", &comando);
		move(comando);
	} while (!acabou());
	freemapa(&m);
}