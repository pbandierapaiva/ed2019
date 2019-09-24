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
		//novoNo->proximo = lista;
		return;
		}
	// insere no início da lista
	novoNo->proximo = p;

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


void swapAdjDL(struct ListaDL *tico) {
	swapDL(tico, tico->proximo);
}

void swapDL(struct ListaDL *tico,struct ListaDL *teco) {
	struct ListaDL *p;
	
	p= teco->anterior;
	teco->anterior=tico->anterior;
	tico->anterior = p;
	p= teco->proximo;
	teco->proximo = tico->proximo;
	tico->proximo = p;
}

//ordena


void ordenaDL(struct ListaDL *raiz) {
	struct ListaDL *p, *q;
	int alterou=1;

	p= raiz->proximo;
	if(!p) return;
	while( alterou ) {
		alterou=0;
		while(p->proximo!=raiz) {
			if( strcmp( p->nome , p->proximo->nome ) < 0 ) {
				swapAdjDL(p);
				alterou=1;
				}
			p = p->proximo;
		}
	}


}







