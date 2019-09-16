/* Arquivo: listaligada.h
* 	Definição de estrutura para lista ligada 'ListaLigada'
*/
//#define _GNU_SOURCE

struct No {
	long int valor;
	struct No *proximo;
};

void insere(long int valor, struct No *raiz);
long int remover(struct No *raiz);

