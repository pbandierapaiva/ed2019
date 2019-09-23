/* Arquivo arvore.h

	Protótipos e estrutura de dados de árvore binária

*/

struct arvore {
	int nodeVal;
	struct arvore *pe, *pd;
	};

void insere(int valor, struct arvore **noraiz);
void imprime(struct arvore *no);

int maximo(int a, int b);
int profundidade(struct arvore *no);
