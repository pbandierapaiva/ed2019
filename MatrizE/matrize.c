/* matrize.c
* Implementa e testa matrizes esparsas
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "matrize.h"


int main() {
	MatrizE raiz;

	raiz.lin = -1;
	raiz.col = -1;
	raiz.direita=&raiz;
	raiz.baixo=&raiz;

}

MatrizE *achaCol(MatrizE *noRaiz, int coluna) {
	MatrizE *p, *q, *novaCol;

	p= noRaiz;
	q=p;
	while(p->direita!=noRaiz) {
		if( p->col == coluna )
			return p;
		if( coluna > p->col ){
			q = p;
			p = p->direita;
			}
		else
			break;
		}
	novaCol = malloc(sizeof(MatrizE));
	novaCol->col = coluna;
	novaCol->baixo = novaCol;
	novaCol->direita = q->direita;
	q->direita = novaCol;
	return novaCol;
}

MatrizE *achaLin(MatrizE *noRaiz, int linha) {
	MatrizE *p, *q, *novaLin;

	p= noRaiz;
	q=p;
	while(p->baixo!=noRaiz) {
		if( p->lin == linha )
			return p;
		if( linha > p->lin ){
			q = p;
			p = p->baixo;
			}
		else
			break;
		}
	novaLin = malloc(sizeof(MatrizE));
	novaLin->lin = linha;
	novaLin->direta = novaLin;

	novaLin->abaixo = q->abaixo;
	q->abaixo = novaLin;
	return novaLin;
}

void insereNoCol(MatrizE *pCol, MatrizE *no, int linha) {
	MatrizE *p, *q;

	p = pCol->abaixo;
	q = pCol;
	while( p != pCol && linha > p->lin  ) {
		if(  linha == p->lin  ){
			// Nó ja existe
			no->baixo = p->baixo;
			q->baixo = no;
			free(p)
			return;
			}
		q=p;
		p=p->baixo;
		}
	no->baixo = q->baixo;
	q->baixo = no;
}

void insereNoLin(MatrizE *pLin, MatrizE *no, int coluna) {
	MatrizE *p, *q;

	p = pLin->direita;
	q = pLin;
	while( p != pLin &&  coluna > p->col  ) {
		if(  coluna == p->col  ){
			// Nó ja existe
			no->direita = p->direita;
			q->direita = no;
			free(p)
			return;
			}
		q=p;
		p=p->direita;
		}
	no->direita = q->direita;
	q->direita = no;
}


void insere(MatrizE *noRaiz, int i, int j, int val) {
	MatrizE *no, *pLin, *pCol;

	no = malloc(sizeof(MatrizE));
	no->lin = i;
	no->col = j;
	no->valor = val;
	no->direita = no;
	no->baixo = no;

	pLin = achaLin(noRaiz, i);
	pCol = achaCol(noRaiz, j);


	


		

	


} 













