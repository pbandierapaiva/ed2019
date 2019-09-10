/* Arquivo: listaligada.c
* 	Definição de funções que implementam lista ligada.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "listaligada.h"

void insereLL(long int valor, struct ListaLigada *lista) {
	struct ListaLigada *novoNo;
	struct ListaLigada *p;

	novoNo = malloc(sizeof(struct ListaLigada));
	novoNo->valor = valor;
	novoNo->proximo = NULL;

	p = lista->proximo;
	if(p==NULL) {   //Lista vazia
		lista->proximo = novoNo;
		return;
		}
	
	while( p->proximo != NULL )
		p = p->proximo;
	p->proximo = novoNo;

}

void imprimeLL(struct ListaLigada lista) {
	struct ListaLigada *p;

	printf("\nLista ligada: \n");
	p = lista.proximo;
	while( p ){
		printf("\t%ld\n",p->valor);
		p= p->proximo;
	}

}

void removePtrItemLL(struct ListaLigada *item, struct ListaLigada *raiz) {
	struct ListaLigada *p;

	p = raiz;
	while( p->proximo != item  && p != NULL) {
		p = p->proximo;	
	}
	if(p==NULL) {
		printf("\nItem não encontrado.\n");
		return;
	}
		
	p->proximo = p->proximo->proximo;
	free( item );
}

void removeItemPorValorLL(long val, struct ListaLigada *raiz) {
	struct ListaLigada *p;

	p = raiz->proximo;

	while( p ) {
		if( p->valor==val )
			removePtrItemLL(p, raiz);
		p = p->proximo;
	}
}

int main(){

	long int valor, buscaval;
	struct ListaLigada noRaiz; 

	noRaiz.valor=0;
	noRaiz.proximo=NULL;



	while(1) {
		printf("Entre com valor inteiro: ");
		scanf("%ld",&valor);
		if(!valor) break;

		insereLL(valor, &noRaiz);
				
	}
	imprimeLL(noRaiz);

	printf("Entre com valor a ser removido: ");
	scanf("%ld",&valor);
	removeItemPorValorLL(valor, &noRaiz);

	imprimeLL(noRaiz);	


}
