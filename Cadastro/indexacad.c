/*
* Programa: lecadastro.c
* 
* indexacad.c
* Cria arquivo de índece do cadastro
*
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cadastro.h"



int main() {

	int conta=0;

	FILE *fp;
	FILE *ofp;

	struct Cadastro reg; 



	fp = fopen("../data/cadstru.arq","r");
	ofp = fopen("../data/cadstru.ndx","w");

	
	if( !fp || !ofp ) {
		printf("Erro ao abrir arquivos.\n");
		return 1;
		}
	
	while( fread( &reg, sizeof(reg), 1, fp )==1 ) {
		fprintf(ofp, "%ld %s\n",conta, reg.NOME);
		conta++;
		}
	fclose(fp);
	fclose(ofp);

	return 0;
}














































