/* Arquivo: .c
* 	Definição de funções que implementam árvores binárias.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "arvore.h"

// Programa principal para testar a ArvoreB
int main() {
	ArvoreB *raiz = NULL;
	int h=0, c=0;

	entraDados(&raiz);
	imprimeEmOrdem( raiz );
	
	printf("Profundidade: %d\n", altura(raiz));
	printf("Número de nós: %d\n", contaNos(raiz));
	if(eBalanceada(raiz)) 
		printf("A árvore é balanceada!\n");
	else
		printf("A árvore não está balanceada!\n");

	apaga(&raiz);
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
		printf("Árvore vazia\n");
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

int contaNos(ArvoreB *no) {
	if(!no) return 0;
	return 1+ contaNos(no->pe)+contaNos(no->pd);
	}
	
// Retorna a  altura de uma árvore abaixo do nó
int altura(ArvoreB *no) {
	if( !no )
		return 0;
	return 1+maximo(altura(no->pe),altura(no->pd));
	}
	
//int profundidade(ArvoreB *no) {}

int eBalanceada(ArvoreB *no) {
	return (contaNos(no) > (1<<(altura(no)-1))-1); 
}

void apaga(ArvoreB **no) {
		if(! no || ! *no) return;
		apaga(&((*no)->pe));
		apaga(&((*no)->pd));
		free(*no);
		*no=NULL;
		return;
}










