/*
* Programa: c.c
* 
* Busca nome em arquivo indexado, recupera registro, cronometra o tempo de busca
*
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>   	// para toupper()
#include <time.h>	// para clock()

#include "cadastro.h"


int main() {
	char nomebusca[100];
	Cadastro registro;
	long int i;

	char *p;
	clock_t inicio, fim;

	FILE *fp, *ndxfp;

	// Abre arquivos de dados e de índice
	if( !(ndxfp = fopen("cadstru.ndx","r")) ) {
		printf("Erro ao abrir arquivo índice.\n");
		return 1;
		}
	if( !(fp = fopen("cadstru.arq","r")) ) {
		printf("Erro ao abrir arquivo de dados.\n");
		return 1;
		}

	
	while(1) {
		printf("Entre com nome para busca (Ctrl+C termina): ");
		fgets( nomebusca, 100, stdin);
		nomebusca[ strlen(nomebusca)-1 ] = '\0';

		// transforma o string para maiúsculas
		p = nomebusca;
		while( *p!='\0' && *p!='\n') {
			*p = toupper(*p);
			p++;
			}
		*p = '\0';

		inicio = clock();

		i =  buscaIndexNome( ndxfp, nomebusca );
		if( i==NAOENCONTRADO ){ // Não encontrado
			printf("\nRegistro não encontrado\n\n");
			continue;
			}
		pegaRegPorIndex(&registro, fp, i);
		printf("\nNome: \t%s\nLotação: \t%s\nCargo: \t%s\n\n",
					registro.NOME, registro.UORG_LOTACAO, registro.DESCRICAO_CARGO);

		fim = clock();
		printf("Tempo de consulta %f s\n%ld\n", (double)(fim - inicio) / CLOCKS_PER_SEC, fim);
		}

	return 0;
}











