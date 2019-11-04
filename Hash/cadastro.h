/* Arquivo: cadastro.h
* 	Definição de estrutura "Cadastro" e protótipos de funções de gravação de CSV para arquivo estruturado 
*/
#define NAOENCONTRADO -1

 	

typedef struct Cadastro {
	char  Id_SERVIDOR_PORTAL[10];
	char  NOME[100];
	char  DESCRICAO_CARGO[50];
	char  CLASSE_CARGO[3];
	char  REFERENCIA_CARGO[3];
	char  PADRAO_CARGO[4];
	char  NIVEL_CARGO[4];
	char  FUNCAO[50];
	char  CODIGO_ATIVIDADE[5];
	char  ATIVIDADE[40];
	char  UORG_LOTACAO[50];
	char  ORG_LOTACAO[50];
	char  ORGSUP_LOTACAO[50];
	char  UORG_EXERCICIO[50];
	char  ORG_EXERCICIO[50];
	char  ORGSUP_EXERCICIO[50];
	char  TIPO_VINCULO[2];
	char  SITUACAO_VINCULO[30];
	char  DATA_INICIO_AFASTAMENTO[15];
	char  DATA_TERMINO_AFASTAMENTO[15];
	char  REGIME_JURIDICO[40];
	char  JORNADA_DE_TRABALHO[30];
	char  DATA_INGRESSO_CARGOFUNCAO[15];
	char  DATA_NOMEACAO_CARGOFUNCAO[15];
	char  DATA_INGRESSO_ORGAO[15];
	char  DATA_DIPLOMA_INGRESSO_SERVICOPUBLICO[15];
	char  DIPLOMA_INGRESSO_CARGOFUNCAO[15];
	char  DIPLOMA_INGRESSO_ORGAO[30];
	char  DIPLOMA_INGRESSO_SERVICOPUBLICO[30];
	char  UF_EXERCICIO[3];
	} Cadastro;











