/* Arquivo: listaligada.h
* 	Definição de estrutura para lista ligada 'ListaLigada'
*/
//#define _GNU_SOURCE

struct ListaDL {
	long int valor;
	struct ListaDL *anterior;
	struct ListaDL *proximo;

};

void insereDL(long int, struct ListaDL *);
void imprimeDL(struct ListaDL);
void removePtrDL(struct ListaDL *, struct ListaDL *);
void removeItemPorValorDL(long, struct ListaDL *);

