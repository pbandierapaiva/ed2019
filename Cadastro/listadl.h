/* Arquivo: listaligada.h
* 	Definição de estrutura para lista ligada 'ListaLigada'
*/


struct ListaDL {
	long int indice;
	char nome[100];
	struct ListaDL *anterior;
	struct ListaDL *proximo;

};

void insereDL(long int, char *, struct ListaDL *);
void imprimeDL(struct ListaDL);
void apagaDL(struct ListaDL *);
void swapAdjDL(struct ListaDL *);
void swapDL(struct ListaDL *,struct ListaDL *);
void ordenaDL(struct ListaDL *);

