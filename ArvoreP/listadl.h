/* Arquivo: listaligada.h
* 	Definição de estrutura para lista ligada 'ListaLigada'
*/

struct listadl {
	ArvoreP no;
	struct listadl *anterior;
	struct listadl *proximo;

};
typedef struct listadl ListaDL;


void insereDL(long int,  ListaDL *);
void imprimeDL( ListaDL);
void removePtrDL( ListaDL *,  ListaDL *);
void removeItemPorValorDL(long,  ListaDL *);

