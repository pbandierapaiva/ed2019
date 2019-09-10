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

	if(lista->proximo) {
		novoNo->proximo = lista->proximo;
		lista->proximo = novoNo;
		}	
	else {
		lista->proximo = novoNo;
		}
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

int main(){

	long int valor;
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



}
