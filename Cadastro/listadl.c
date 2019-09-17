/* Arquivo: listaligada.c
* 	Definição de funções que implementam lista ligada.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "listadl.h"

void insereDL(long int valor, char *nome, struct ListaDL *lista) {
	struct ListaDL *novoNo;
	struct ListaDL *p;

	novoNo = malloc(sizeof(struct ListaDL));
	novoNo->indice = valor;
	novoNo->proximo = NULL;
	strcpy(novoNo->nome, nome);
	novoNo->anterior = NULL;

	p = lista->proximo;
	if(p==NULL) {   //Lista vazia
		lista->proximo = novoNo;
		novoNo->anterior = lista ;
		return;
		}
	// vou até o final da lista
	while( p->proximo != NULL )
		p = p->proximo;
	p->proximo = novoNo;
	novoNo->anterior = p;

}

void imprimeDL(struct ListaDL lista) {
	struct ListaDL *p;

	printf("\nLista duplamente ligada: \n");
	p = lista.proximo;
	while( p ){
		printf("\t%ld\t%s\n",p->indice,p->nome);
		p= p->proximo;
	}

}

void apagaDL(struct ListaDL *lista) {
	struct ListaDL *p, *q;

	printf("\nApagando Lista duplamente ligada... \n");
	p = lista->proximo;
	lista->proximo = NULL;
	lista->anterior = NULL;
	while( p ){
		q = p->proximo;
		free(p);	
		p=q;
	}
}

void removePtrDL(struct ListaDL *item, struct ListaDL *raiz) {
	item->anterior->proximo = item->proximo;
	if( item->proximo )
		item->proximo->anterior = item->anterior;

	free( item );
}

void removeItemPorValorDL(long val, struct ListaDL *raiz) {
	struct ListaDL *p;

	p = raiz->proximo;

	while( p ) {
		if( p->indice==val )
			removePtrDL(p, raiz);
		p = p->proximo;
	}
}

