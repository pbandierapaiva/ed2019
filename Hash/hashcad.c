/*
* Programa: hash.c
* Cria uma tabela de dispersão
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cadastro.h"

#define MAX_TABLE 20000000

typedef struct {
	char chave[100];
	long int arqind;
} ITEM;


long int calculaHash(const char * str) {
	int hash = 7039;
	int c;

	while (*str != '\0') {
		hash = ((hash << 4) + (int)(*str)) % MAX_TABLE;
		str++;
	}
	return hash % MAX_TABLE;
}


int main() {
	FILE *fp;
	long int contareg=0, colisao=0;
	long int curHash;
	Cadastro reg;
	ITEM *hash;

	hash = malloc(sizeof(ITEM)*MAX_TABLE);

	memset(hash,0,MAX_TABLE);

	fp = fopen("../data/cadstru.arq","r");
		
	if( !fp ) {
		printf("Erro ao abrir arquivos.\n");
		return 1;
		}

	while( fread( &reg, sizeof(reg), 1, fp )==1 ) {
		curHash = calculaHash(reg.NOME);
		printf("\n%ld", curHash);
		if( hash[ curHash ].chave[0] != 0 ) {
			if(strcmp( hash[ curHash ].chave, reg.NOME) ){ 
				 //printf("\nColisão-> \n%s %s \n%ld %ld",
				//	hash[ curHash ].chave, reg.NOME, 
				//	contareg, curHash);
					colisao++;		
				}
			}

		strcpy(hash[ curHash ].chave, reg.NOME);
		hash[ curHash ].arqind =contareg;
		contareg++;
		}
	fclose(fp);
//	printf("Número de colisões: %ld\n", colisao);

}
