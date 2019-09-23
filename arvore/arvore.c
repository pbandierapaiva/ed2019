

/* Arquivo: .c
* 	Definição de funções que implementam árvores binárias.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "arvore.h"



int main() {

	struct arvore *raiz, *paux;
	int valor;
	raiz = NULL;



	imprime( raiz );

	while(1) {
		printf("Entre com valor inteiro positivo (0 termina): ");
		scanf("%d",&valor);
		if(!valor) break;
		insere(valor, &raiz);				
		}

	imprime( raiz );

	return 0;
}

void insere(int valor, struct arvore **noraiz) {
	struct arvore *p;

	if( *noraiz == NULL ){  // ! *noraiz
		p = malloc(sizeof(struct arvore));
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

void imprime(struct arvore *no) {  //imprime em-ordem
	if( no==NULL ){
		printf("No nulo\n");
		return;
		}
	if( no->pe )
		imprime(no->pe);
	printf("%d\n", no->nodeVal);
	if( no->pd )
		imprime(no->pd);	
	}





