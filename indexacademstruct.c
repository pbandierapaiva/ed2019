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

	cadastro reg; 
	indexcad ndx;


	fp = fopen("cadstru.arq","r");
	ofp = fopen("cadstru.ndx","wb");

	
	if( !fp || !ofp ) {
		printf("Erro ao abrir arquivos.\n");
		return 1;
		}
	
	while( fread( &reg, sizeof(reg), 1, fp )==1 ) {
		
		strcpy(ndx.NOME, reg.NOME);
		ndx.offset = conta;
		fwrite( &ndx, sizeof(ndx), 1, ofp);
		conta++;
		}
	fclose(fp);
	fclose(ofp);

	return 0;
}














































