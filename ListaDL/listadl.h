/* Arquivo: listaligada.h
* 	Definição de estrutura para lista ligada 'ListaLigada'
*/
//#define _GNU_SOURCE

struct listadl {
	long int valor;
	struct listadl *anterior;
	struct listadl *proximo;

};
typedef struct listadl ListaDL;


void insereDL(long int,  ListaDL *);
void imprimeDL( ListaDL);
void removePtrDL( ListaDL *,  ListaDL *);
void removeItemPorValorDL(long,  ListaDL *);

