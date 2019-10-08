/* matrize.c
* Implementa e testa matrizes esparsas
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "matrize.h"


int main() {
	MatrizE raiz;
	int l,c;
	int val;

	raiz.lin = -1;
	raiz.col = -1;
	raiz.direita=&raiz;
	raiz.abaixo=&raiz;
	
	while( 1 ){
		printf("Entre com inteiros para linha coluna valor (0 0 0 termina): ");
		scanf("%d %d %d", &l, &c, &val);
		if(l==0) break;
		insere(&raiz, l, c, val);
	}
	imprimeMatriz(&raiz);
}

// pegaCol
// Recebe raiz da Matriz esparsa e coluna
// Retorna ponteiro para coluna (já existente ou criada caso
// não exista)
MatrizE *pegaCol(MatrizE *noRaiz, int coluna) {
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
	novaCol->abaixo = novaCol;
	novaCol->direita = q->direita;
	q->direita = novaCol;
	return novaCol;
}


// pegaLin
// Recebe raiz da Matriz esparsa e número da linha
// Retorna ponteiro para linha (já existente ou criada caso
// não exista)
MatrizE *pegaLin(MatrizE *noRaiz, int linha) {
	MatrizE *p, *q, *novaLin;

	p= noRaiz;
	q=p;
	while(p->abaixo!=noRaiz) {
		if( p->lin == linha )
			return p;
		if( linha > p->lin ){
			q = p;
			p = p->abaixo;
			}
		else
			break;
		}
	novaLin = malloc(sizeof(MatrizE));
	novaLin->lin = linha;
	novaLin->direita = novaLin;

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
			no->abaixo = p->abaixo;
			q->abaixo = no;
			free(p);
			return;
			}
		q=p;
		p=p->abaixo;
		}
	no->abaixo = q->abaixo;
	q->abaixo = no;
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
			free(p);
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
	no->abaixo = no;

	pLin = pegaLin(noRaiz, i);
	pCol = pegaCol(noRaiz, j);
	insereNoLin(pLin, no, i);
	insereNoCol(pCol, no, j);
}

int nColunas(MatrizE *raiz) {
	MatrizE *pCol;
	int tam=0;
	pCol = raiz->direita;
	while(pCol!=raiz) {
		tam = pCol->col;
		pCol = pCol->direita;
	}
	return tam;
}
	
// imprimeMatriz
// Imprime matriz esparsa completa (com 0 onde não há nó)
void imprimeMatriz(MatrizE *raiz) {
	MatrizE *pLinha, *pNo;
	int largura;
	int linhaCorrente=1, colCorrente;
	
	largura = nColunas(raiz);
	printf("\nImprimindo matriz esparsa largura: %d.\n",largura);

	pLinha= raiz->abaixo;
	while(pLinha != raiz) {
		printf("Linha: %d\n", linhaCorrente);
		if(pLinha->lin > linhaCorrente) {
			for(int i=0;i<largura;i++)
				printf("0\t");
			linhaCorrente++;
		}
		pNo= pLinha->direita;
		colCorrente=1;
		while(pNo != pLinha) {
			while(pNo->col > colCorrente) {
				printf("0\t");
				colCorrente++;
			}
			printf("%d\t",pNo->valor);
			colCorrente++;
			pNo= pLinha->direita;
		}
		while(colCorrente<largura) {
			printf("0\t");
			colCorrente++;
		}
		printf("\n");
		colCorrente=1;
	}
}

void imprimeLinha(MatrizE *raiz, int linha) {
	MatrizE *p;
	
	p=raiz.abaixo;
}
	
	
}