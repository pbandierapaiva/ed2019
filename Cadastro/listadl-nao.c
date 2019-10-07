/* Arquivo: listaligada.c
* 	Definição de funções que implementam lista ligada de índices e nomes do cadastro.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "listadl.h"

// Função: insereDL
// Recebe valor(indice), nome e estrutura para lista ligada
void insereDL(long int valor, char *nome, struct ListaDL *lista) {
	struct ListaDL *novoNo;
	struct ListaDL *p;

	novoNo = malloc(sizeof(struct ListaDL));
	novoNo->indice = valor;
	strcpy(novoNo->nome, nome);
	novoNo->anterior = lista;

	p = lista->proximo;
	lista->proximo = novoNo;
	if(p==NULL) {   //Lista vazia
		novoNo->proximo = NULL;
		return;
		}
	// insere no início da lista
	novoNo->proximo = p;
	p->anterior = novoNo;

}

// Função: imprimeDL
// Recebe lista ligada e imprime todos os elementos da lista
void imprimeDL(struct ListaDL lista) {
	struct ListaDL *p;

	printf("\nLista duplamente ligada: \n");
	p = lista.proximo;
	while( p ){
		printf("\t%ld\t%s\n",p->indice,p->nome);
		p= p->proximo;
	}

}

// Função apagaDL
// Recebe ponteiro para raiz de lista ligada
// Apaga todos os elementos da lista liberando a memória ocupada
void apagaDL(struct ListaDL *lista) {
	struct ListaDL *p, *q;

	printf("\nApagando Lista duplamente ligada... ");
	p = lista->proximo;
	lista->proximo = NULL;
	lista->anterior = NULL;
	while( p && p!=lista){
		q = p->proximo;
		free(p);	
		p=q;
	}
	printf("apagada.\n");
}

long int contaDL(struct ListaDL *raiz) {
	long int i=0;
	struct ListaDL *p;

	p = raiz->proximo;

	while( p ) {
		i++;
		p=p->proximo;
		}	
	return i;
}

void swapAdjDL(struct ListaDL *tico) {
	swapDL(tico, tico->proximo);
}

void swapDL(struct ListaDL *a,struct ListaDL *b) {
	struct ListaDL *p;

	a->anterior->proximo=b;
	if(b->proximo)
		b->proximo->anterior=a;
	p = a->anterior;
	a->anterior = b;
	b->anterior = p;
	p = b->proximo;
	b->proximo = a;
	a->proximo = p;
}

// Ordena utilizando algoritmo semelhante ao Bubblesort
void ordenaDL(struct ListaDL *raiz) {
	struct ListaDL *p, *q, *inicioLista, *finalLista;
	long int tamanho, conta;
	int alterou=1;

	q = raiz->proximo;
	while( q ) {
		tamanho++;
		p = q;
		q=q->proximo;
		}
	finalLista = p;  // q é o último elemento da lista

	inicioLista = raiz->proximo;

	p = inicioLista;
	q = finalLista;
	if(!p) return; //lista vazia
	while( alterou ) {
		alterou=0;
		while(p && p->proximo && q && q->anterior ){
                          //&& conta ) { //p->proximo NULL quando chega ao final da lista
			if( strcmp( p->nome , p->proximo->nome ) > 0 ) {
	printf("\nTrocou p: %s, %s", p->nome , p->proximo->nome );
				swapAdjDL(p);
				alterou=1;
				}
			if( p!=q->anterior && strcmp( q->anterior->nome, q->nome) > 0 ) {
	printf("\nTrocou q-ant: %s, %s", q->anterior->nome, q->nome );
				swapAdjDL(q->anterior);
				alterou=1;
				}
	imprimeDL(*raiz);
			conta--;
			p = p->proximo;
			q = q->anterior;
		}

		inicioLista = inicioLista->proximo;
		p = inicioLista; // volta ao início da lista
		finalLista = finalLista->anterior;
		q = finalLista;
	}


}







