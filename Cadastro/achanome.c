/*
* Programa: achanome.c
* 
* Busca nome em arquivo indexado
*
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cadastro.h"



int main() {
	char nomebusca[100];
	char buf[100];
	char *p, *q;
	long int indice;
	cadastro reg;

	FILE *fp;
	FILE *ndxfp;
	

	printf("Entre com nome para busca: ");
	fgets( nomebusca, 100, stdin);
	nomebusca[ strlen(nomebusca)-1 ] = '\0';

	ndxfp = fopen("cadstru.ndx","r");
	fp = fopen("cadstru.arq","r");

	if( !fp || !ndxfp ) {
		printf("Erro ao abrir arquivos.\n");
		return 1;
		}
	while( fgets( buf, 100, ndxfp) ) {
		p=buf;
		while(*p!=' ') p++;
		*p = '\0';		
		indice = atol(buf);
		
		p++; // chegar no NOME

		p[strlen(p)-1]='\0'; //remove \n


		if( !strcmp( p, nomebusca ) ){
			printf("Achou! %ld\n", indice);
	
			fseek( fp, indice*sizeof(reg), 0);
			fread( &reg, sizeof(reg), 1, fp);
			printf("Nome: %s\n Lotação: %s\nCargo: %s\n\n",
				reg.NOME, reg.UORG_LOTACAO, reg.DESCRICAO_CARGO);

			return 0;
			}

		//printf("%s %s\n",nomebusca, p);
		

		}
	printf("Nome não encontrado");
	return 1;
	



	
}




