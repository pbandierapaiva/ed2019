/*
* Arquivo: cadutil.c
* 
* Funções para busca nome em arquivo indexado, 
* recuperação de registro
*
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cadastro.h"
#include "listadl.h"

int buscaListaIndexNome(FILE *ndx, char *nome, struct ListaDL *lista) {
	char buf[100];
	int indice;
	int conta=0;
	char *p;

	rewind(ndx); //retorna o ponteiro para o início do arquivo

	apagaDL( lista ); 

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
			insereDL(indice, lista); 
			conta++;
			}
		}
	// Nome não encontrado
	return conta;
}






//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Função: buscaVetorIndexNome
// 	Busca nome em arquivo índice, colocando num vetor de long int
// Recebe: ponteiro para arquivo de índice aberto, nome para busca, 
//	endereço do vetor para retorno  
// Retorna: número de achados (int), em caso de erro -1 (NAOENCONTRADO)
int buscaVetorIndexNome(FILE *ndx, char *nome, long *vet) {
	char buf[100];
	int indice;
	int conta=0;
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
			vet[conta]= indice;
			conta++;
			}
		}
	// Nome não encontrado
	return conta;
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
int pegaRegPorIndex(Cadastro *reg, FILE *arq, int ind) {
	fseek( arq, ind*sizeof(Cadastro), SEEK_SET);  // SEEK_SET = início do arquivo
	fread( reg, sizeof(Cadastro), 1, arq);
	return 1;
}



