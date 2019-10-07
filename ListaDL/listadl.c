/* Arquivo: listadl.c
* 	Definição de funções que implementam lista duplamente ligada: ListaDL.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "listadl.h"

void insereDL(long int valor, ListaDL *lista) {
	ListaDL *novoNo;
	ListaDL *p;

	novoNo = malloc(sizeof(ListaDL));
	novoNo->valor = valor;
	novoNo->proximo = NULL;
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

void imprimeDL(ListaDL lista) {
	ListaDL *p;

	printf("\nLista duplamente ligada: \n");
	p = lista.proximo;
	while( p ){
		printf("\t%ld\n",p->valor);
		p= p->proximo;
	}

}

void removePtrDL(ListaDL *item, ListaDL *raiz) {



	item->anterior->proximo = item->proximo;
	if( item->proximo )
		item->proximo->anterior = item->anterior;

	free( item );
}

void removeItemPorValorDL(long val, ListaDL *raiz) {
	ListaDL *p;

	p = raiz->proximo;

	while( p ) {
		if( p->valor==val )
			removePtrDL(p, raiz);
		p = p->proximo;
	}
}

int main(){

	long int valor, buscaval;
	ListaDL noRaiz; 

	noRaiz.valor=0;
	noRaiz.proximo=NULL;
	noRaiz.anterior=NULL;


	while(1) {
		printf("Entre com valor inteiro: ");
		scanf("%ld",&valor);
		if(!valor) break;

		insereDL(valor, &noRaiz);
				
	}
	imprimeDL(noRaiz);

	printf("Entre com valor a ser removido: ");
	scanf("%ld",&valor);
	removeItemPorValorDL(valor, &noRaiz);

	imprimeDL(noRaiz);	


}
