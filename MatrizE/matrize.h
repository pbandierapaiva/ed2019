/* Arquivo: matrize.h
* 	Definição de estrutura para Matriz esparsa 'MatrizE'
*/

struct matrize {
	int  valor;
	
	int lin, col;
	struct matrize *direita, *abaixo;

};
typedef struct matrize MatrizE;


