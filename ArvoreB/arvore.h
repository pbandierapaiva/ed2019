/* Arquivo arvore.h

	Protótipos e estrutura de dados de árvore binária

*/

struct arvore {
	int nodeVal;
	struct arvore *pe, *pd;
	};

typedef struct arvore ArvoreB;

void insere(int , ArvoreB **);
void imprimeEmOrdem(ArvoreB *);
void entraDados(ArvoreB **);
int maximo(int, int );
int altura(ArvoreB *);
int contaNos(ArvoreB *);
int eBalanceada(ArvoreB *);
