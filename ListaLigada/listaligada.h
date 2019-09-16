/* Arquivo: listaligada.h
* 	Definição de estrutura para lista ligada 'ListaLigada'
*/
//#define _GNU_SOURCE

struct ListaLigada {
	long int valor;
	struct ListaLigada *proximo;
};


void insereLL(long int, struct ListaLigada *);
void imprimeLL(struct ListaLigada);
void removePtrItemLL(struct ListaLigada *, struct ListaLigada *);
void removeItemPorValorLL(long, struct ListaLigada *);

