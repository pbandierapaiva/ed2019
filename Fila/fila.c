/* Arquivo: listaligada.c
* 	Definição de funções que implementam lista ligada.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "fila.h"

void insere(long int valor, struct No *raiz) {
	struct No *novoNo;
	struct No *p;

	novoNo = malloc(sizeof(struct No));
	novoNo->valor = valor;
	novoNo->proximo = NULL;

	p = raiz->proximo;
	if(p==NULL) {   //Lista vazia
		raiz->proximo = novoNo;
		return;
		}
	
	while( p->proximo != NULL )
		p = p->proximo;
	p->proximo = novoNo;
}

long int remover(struct No *raiz) {
	long int val;
	struct No *p;

	p = raiz->proximo;
	
	if( p==NULL ) {
		printf("Fila vazia\n");
		return 0;
		}	
	val = p->valor;
	raiz->proximo = p->proximo;
	free(p);
	return val;	
}


int main(){

	long int valor;
	char es;
	struct No noRaiz; 

	noRaiz.valor=0;
	noRaiz.proximo=NULL;


	while(1) {
		printf("\nEntrando ou saindo (E/S): ");
		scanf("%c",&es);

		if(toupper(es)=='E') {
			printf("Entre com valor inteiro: ");
			scanf("%ld",&valor);
			insere(valor, &noRaiz);
			printf("OK\n");
			}
		if(toupper(es)=='S') 
			printf("%ld\n",remover(&noRaiz));				
	}
}









