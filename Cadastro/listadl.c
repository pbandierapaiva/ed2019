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
	novoNo->proximo = NULL;
	strcpy(novoNo->nome, nome);
	novoNo->anterior = NULL;

	p = lista->proximo;
	if(p==NULL) {   //Lista vazia
		lista->proximo = novoNo;
		novoNo->anterior = lista ;
		return;
		}
	// insere no início da litsa
	novoNo->proximo = p;
	lista->proximo=novoNo;
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
