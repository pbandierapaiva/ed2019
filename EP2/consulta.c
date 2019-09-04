/*
* Programa: achanome.c
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
	cadastro registro;
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Função: buscaIndexNome
// 	Busca nome em arquivo índice
// Recebe: ponteiro para arquivo de índice aberto e nome para busca 
// Retorna: indice (int), em caso de erro -1 (NAOENCONTRADO)
int buscaIndexNome(FILE *ndx, char *nome) {

	char buf[100];
	int indice;
	char *p;

	rewind(ndx); //retorna o ponteiro para o início do arquivo

	while( fgets( buf, 100, ndx) ) {
		// extrai de buf o número do índice
		p=buf;
		while(*p!=' ') p++;
		*p = '\0';		
		indice = atol(buf);
		
		p++; // p aponta para o início do NOME
		p[strlen(p)-1]='\0'; //remove \n

		if( strstr( p, nome ) ){ // True se encontrou substring
			// achou nome
			return indice;
			}
		}
	// Nome não encontrado
	return NAOENCONTRADO;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Função: pegaRegPorIndex
// 	Recupera registro a partir de índice
// Recebe: 
//		ponteiro para registro (struct cadastro) 
//		ponteiro para arquivo de dados aberto
//		indice 
// Retorna: 0 em caso de erro (o registro recuperado é colocado no endereço recebido)
int pegaRegPorIndex(cadastro *reg, FILE *arq, int ind) {
	fseek( arq, ind*sizeof(cadastro), SEEK_SET);  // SEEK_SET = início do arquivo
	fread( reg, sizeof(cadastro), 1, arq);
	return 1;
}
