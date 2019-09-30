/* Arquivo: cadutil.h
* 	Protótipos de funções utilitárias para o cadastro
*/

int buscaIndexNome(FILE *, char *);
int buscaListaIndexNome(FILE *, char *, struct ListaDL *);
int pegaRegPorIndex(Cadastro *, FILE *, int);
int buscaNome( char *, struct ListaDL,  struct ListaDL *);
long int carregaIndice(char *, struct ListaDL *);

