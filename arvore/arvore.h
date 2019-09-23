/* Arquivo arvore.h
*/

struct arvore {
	int nodeVal;
	struct arvore *pe, *pd;
	};

void insere(int valor, struct arvore **noraiz);
void imprime(struct arvore *no);
