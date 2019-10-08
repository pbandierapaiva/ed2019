/* Arquivo: matrize.h
* 	Definição de estrutura para Matriz esparsa 'MatrizE'
*/

struct matrize {
	int  valor;
	
	int lin, col;
	struct matrize *direita, *abaixo;

};
typedef struct matrize MatrizE;

// protótipos das funções
MatrizE *pegaCol(MatrizE *, int );
MatrizE *pegaLin(MatrizE *, int );
void insereNoCol(MatrizE *, MatrizE *, int );
void insereNoLin(MatrizE *, MatrizE *, int );
void insere(MatrizE *, int , int , int );
void imprimeMatriz(MatrizE *);
MatrizE *achaLinha(MatrizE *raiz, int linha);
void imprimeLinha(MatrizE *raiz, int linha);
int nLinhas(MatrizE *raiz);
int nColunas(MatrizE *raiz);
