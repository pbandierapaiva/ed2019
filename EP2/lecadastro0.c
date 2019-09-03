/*
* Programa: lecadastro.c
* 
* Lê arquivo CSV
*
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>


#define MAXREG 1000

int leCadastro(char *, void *);

typedef struct CADASTRO {
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
	} cadastro;

int main() {

	int num=0;


	setlocale(LC_ALL,"pt_BR.ISO-8859-1");

	cadastro sala[MAXREG];


	num = leCadastro("cadastro2019.csv",sala);


	for( int j=0; j<num; j++) {
		//printf("Nome %s", sala[j].nome,sala[j].peso, sala[j].altura);
		printf("Nome %s Cargo: %s\n",sala[j].NOME, sala[j].DESCRICAO_CARGO);
 printf("%s\n", "ÎÇÈÌ");

		if(j>=MAXREG) break;	
		}
	return 0;
}

int leCadastro(char *nomeArq, void *sptr) {
	FILE *fp;
	int i=0;
	char buf[1000]="";
	char *p, *q;
	cadastro *s;
	
	s = sptr;

	fp=fopen(nomeArq,"r");
	if( !fp  ) {
		printf("Erro ao ler arquivo\n");
		return 1;
		}
	
	while( !feof(fp) ){
		fgets(buf, 1000,  fp);

		p = buf;
		while( *p!='|' ) p++; //ignora o primeiro campo
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].Id_SERVIDOR_PORTAL,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].NOME,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].DESCRICAO_CARGO,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].CLASSE_CARGO,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].REFERENCIA_CARGO,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].PADRAO_CARGO,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].NIVEL_CARGO,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].FUNCAO,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].CODIGO_ATIVIDADE,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].ATIVIDADE,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].UORG_LOTACAO,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].ORG_LOTACAO,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].ORGSUP_LOTACAO,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].UORG_EXERCICIO,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].ORG_EXERCICIO,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].ORGSUP_EXERCICIO,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].TIPO_VINCULO,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].SITUACAO_VINCULO,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].DATA_INICIO_AFASTAMENTO,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].DATA_TERMINO_AFASTAMENTO,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].REGIME_JURIDICO,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].JORNADA_DE_TRABALHO,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].DATA_INGRESSO_CARGOFUNCAO,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].DATA_NOMEACAO_CARGOFUNCAO,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].DATA_INGRESSO_ORGAO,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].DATA_DIPLOMA_INGRESSO_SERVICOPUBLICO,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].DIPLOMA_INGRESSO_CARGOFUNCAO,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].DIPLOMA_INGRESSO_ORGAO,q);
		p++;
		q=p;
		while( *p!='|' ) p++;
		*p = '\0';
		strcpy(s[i].DIPLOMA_INGRESSO_SERVICOPUBLICO,q);
		p++;
		q=p;
		while( *p!='\n' && *p!='\0' ) p++;
		*p = '\0';
		strcpy(s[i].UF_EXERCICIO,q);
  
		i++;
		if(i>=MAXREG) break;
		}

	return i; // retorna numero de registros lidos
}









