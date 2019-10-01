/* Arquivo: .c
* 	Definição de funções que implementam árvores binárias.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "arvore.h"

// Programa principal para testar a ArvoreB
int main() {
	ArvoreB *raiz, *paux;
	raiz = NULL;

	entraDados(&raiz);
	imprimeEmOrdem( raiz );
	printf("Profundidade: %d\n",profundidade(raiz));
	return 0;
}

// Entrada de dados via teclado
void entraDados(ArvoreB **raiz) {
	int valor;

	while(1) {
		printf("Entre com valor inteiro positivo (0 termina): ");
		scanf("%d",&valor);
		if(!valor) break;
		insere(valor, raiz);
		}
	}


void insere(int valor, ArvoreB **noraiz) {
	ArvoreB *p;

	if( *noraiz == NULL ){  // ! *noraiz
		p = malloc(sizeof(ArvoreB));
		p->pe = NULL;
		p->pd = NULL;
		p->nodeVal = valor;
		*noraiz = p;
		return;
		}
	if( valor <= (*noraiz)->nodeVal )
		insere(valor, &( (*noraiz)->pe ) );
	else
		insere(valor, &( (*noraiz)->pd ) );

	}

void imprimeEmOrdem(ArvoreB *no) {  //imprime em-ordem
	if( no==NULL ){
		printf("No nulo\n");
		return;
		}
	if( no->pe )
		imprimeEmOrdem(no->pe);
	printf("%d\n", no->nodeVal);
	if( no->pd )
		imprimeEmOrdem(no->pd);
	}

// Compara dois valores e retorna o maior
int maximo(int a, int b){
	if(a>b) return a;
	return b;
	}

// Retorna a  profundidade de uma árvore abaixo do nó
int profundidade(ArvoreB *no) {
	if( !no )
		return 0;
	return 1+maximo(profundidade(no->pe),profundidade(no->pd));
	}
