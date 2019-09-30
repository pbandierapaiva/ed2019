/*
* Programa: lecadastro.c
* 
* Lê arquivo CSV baixado do transparencia.gov com dados de servidores públicos e grava arquivo estruturado 
* 
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cadastro.h"

#define MAXREG 1000

int main() {

	int num=0;

	num = leCSVgravaStru("../data/cadastro2019.csv","../data/cadstru.arq");
	printf("\nTotal de registros lidos: %d\n\n",num);

	return 0;
}

int leCSVgravaStru(char *nomeArq, char *arqSaida) {

	FILE *fp;
	FILE *ofp;
	int i=0;
	char buf[1500]="";
	char *p, *q;
	//cadastro *s;
	Cadastro reg;
	
	//s = sptr;

	fp=fopen(nomeArq,"r");
	ofp = fopen(arqSaida,"w");
	if( !fp  ) {
		printf("Erro ao ler arquivo\n");
		return 1;
		}
	
	while( fgets(buf, 1000,  fp) ){

		p = buf;
		while( *p!='|'  && *p!='\0' ) p++; //ignora o primeiro campo
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.Id_SERVIDOR_PORTAL,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.NOME,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.DESCRICAO_CARGO,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.CLASSE_CARGO,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.REFERENCIA_CARGO,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.PADRAO_CARGO,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.NIVEL_CARGO,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.FUNCAO,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.CODIGO_ATIVIDADE,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.ATIVIDADE,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.UORG_LOTACAO,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.ORG_LOTACAO,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.ORGSUP_LOTACAO,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.UORG_EXERCICIO,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.ORG_EXERCICIO,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.ORGSUP_EXERCICIO,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.TIPO_VINCULO,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.SITUACAO_VINCULO,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.DATA_INICIO_AFASTAMENTO,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.DATA_TERMINO_AFASTAMENTO,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.REGIME_JURIDICO,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.JORNADA_DE_TRABALHO,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.DATA_INGRESSO_CARGOFUNCAO,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.DATA_NOMEACAO_CARGOFUNCAO,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.DATA_INGRESSO_ORGAO,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.DATA_DIPLOMA_INGRESSO_SERVICOPUBLICO,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.DIPLOMA_INGRESSO_CARGOFUNCAO,q);
		p++;
		q=p;
		while( *p!='|' && *p!='\0'  ) p++;
		*p = '\0';
		strcpy(reg.DIPLOMA_INGRESSO_ORGAO,q);
		p++;
		q=p;
		while( *p!='|'  && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.DIPLOMA_INGRESSO_SERVICOPUBLICO,q);
		p++;
		q=p;
		while( *p!='\n' && *p!='\0' ) p++;
		*p = '\0';
		strcpy(reg.UF_EXERCICIO,q);
  		
		i++;
		if(i%100==0) printf("\r%d",i);
		fwrite(&reg, sizeof(reg), 1, ofp);
		}
	printf("\rFechando arquivo...\n");
	fclose(ofp);
	return i; // retorna numero de registros lidos
}









