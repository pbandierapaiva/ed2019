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

#include "cadastro.h"	// Estrutura do cadastro
#include "listadl.h"	// Estrutura e protótipos de função para lista duplamente ligada
#include "cadutil.h"

int main() {
	char nomebusca[100];
	Cadastro registro;
	long int i;
	//long int vetor[1000000];

	struct ListaDL raiz, *pdl;

	strcpy(raiz.nome,"NO RAIZ");
	raiz.indice=0;
	raiz.proximo=NULL; // Lista vazia

	char *p;
	clock_t inicio, fim;

	FILE *fp, *ndxfp;

	// Abre arquivos de dados e de índice
	if( !(ndxfp = fopen("../data/cadstru.ndx","r")) ) {
		printf("Erro ao abrir arquivo índice.\n");
		return 1;
		}
	if( !(fp = fopen("../data/cadstru.arq","r")) ) {
		printf("Erro ao abrir arquivo de dados.\n");
		return 1;
		}

	
	while(1) {
		printf("Entre com nome para busca (Ctrl+C termina): ");
		fgets( nomebusca, 100, stdin);


		// 
		//nomebusca[strlen(nomebusca)-1] = '\0';

		// transforma o string para maiúsculas e o \n em \0
		p = nomebusca;
		while( *p!='\0' && *p!='\n') {
			*p = toupper(*p);
			p++;
			}
		*p = '\0';


		inicio = clock(); // INICIA CRONOMETRO


		i =  buscaListaIndexNome( ndxfp, nomebusca, &raiz );

		if( i==0 ){ // Não encontrado
			printf("\nRegistro não encontrado\n\n");
			continue;
			}
	
		pdl = raiz.proximo;
		while(pdl) {
			pegaRegPorIndex(&registro, fp, pdl->indice);
			printf("\nNome: \t%s\nLotação: \t%s\nCargo: \t%s\n\n",
					registro.NOME, registro.UORG_LOTACAO, registro.DESCRICAO_CARGO);
			pdl = pdl->proximo;
			}
		printf("Número de ocorrências encontradas: %ld\n",i);
		fim = clock();
		printf("Tempo de consulta %f s\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
		}

	return 0;
}











