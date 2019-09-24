/*
* Arquivo: cadutil.c
* 
* Funções utilitárias para o cadastro. Busca nome em arquivo indexado, recupera registro
*
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cadastro.h"
#include "listadl.h"

// UTILIZANDO LISTA DUPLAMENTE LIGADA
//
// Função: buscaNome
// Recebe ponteiro para arquivo aberto de índice, ponteiro para string com nome e ponteiro para
//	lista ligada que receberá a lista de nomes e índices encontrados
// Retorna: número de nomes encontrados 
int buscaNome( char *nomeBusca, struct ListaDL listaIndice,  struct ListaDL *listaResultado) {
	char buf[100];
	int indice;
	int conta=0;
	struct ListaDL *p;

	apagaDL( listaResultado ); 
	p = listaIndice.proximo;
	while( p ) {
		if( strstr( p->nome, nomeBusca ) ){ // True se encontrou substring
			// achou nome
			insereDL(p->indice, p->nome, listaResultado); 
			conta++;
			}
		p = p->proximo;
		}
	return conta;
}

// UTILIZANDO ACESSO AO ARQUIVO DE INDICE
//
// Função: buscaListaIndexNome
// Recebe ponteiro para arquivo aberto de índice, ponteiro para string com nome e ponteiro para
//	lista ligada que receberá a lista de nomes e índices encontrados
// Retorna: número de nomes encontrados 

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
			insereDL(indice, p, lista); 
			conta++;
			}
		}
	// Nome não encontrado
	return conta;
}


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

// Função: carregaIndice
// Recebe: 
//		ponteiro para registro (struct cadastro) 
//		nome do arquivo de índice
// Retorna:
//		número de registros inseridos na lista

int carregaIndice(char *arqIndice, struct ListaDL *lista){
	FILE *ndxfp;
	char buf[100];
	int indice;
	int conta=0;
	char *p;

	if( !(ndxfp = fopen(arqIndice,"r")) ) {
		printf("Erro ao abrir arquivo índice.\n");
		return 0;
		}
	apagaDL( lista ); 

	printf("Carregando índice na memória\n");
	while( fgets( buf, 100, ndxfp) ) {
		// extrai de buf o número do índice
		p=buf;
		while(*p!=' ') p++;
		*p = '\0';		
		indice = atol(buf);
		
		p++; // p aponta para o início do NOME
		p[strlen(p)-1]='\0'; //remove \n

		insereDL(indice, p, lista); 
		conta++;
		if(conta%100==0) printf("\r%d",conta);
		}
	printf("\r");
	return conta;
}
















