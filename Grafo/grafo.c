/* grafo.c
* Implementa e testa grafos
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXMAT	100

int contem(int *vet, int x, int *tam){
	int *p=vet;

	while( p-vet < *tam ) { 
		if( *p==x ) return p-vet;
		p++;
		}
	vet[*tam] = x;
	*tam +=1;	
	return *tam-1;
}

void imprimeGrafo(int *nos, int *mat, int tam){
	int *p; 

	for( int i=0; i < tam; i++ ) 
		printf("\t%d", nos[i]);
	
	for( int i=0; i < tam; i++ ) {  
		printf("\n%d",nos[i]);
		for( int j=0; j < tam; j++ ) {
			printf("\t%d", mat[i* MAXMAT+j] ); 
	
		}
	} 
	printf("\n");
	



}

int main() {
	int nos[ MAXMAT];
	int matAdj[ MAXMAT][ MAXMAT];

	int a,b, conta=0;
	int ia,ib;

	char linha[ 100];
	FILE *fp;
	
	if( (fp = fopen("ex1.txt","r")) == NULL ) {
		printf("Erro de abertura de arquivo.");
		return -1;
		}

	while( fgets(linha,  100, fp) ) {
		if( linha[0]=='#' ) continue;
		
		if ( linha[strlen(linha)-1]=='\n' ) linha[strlen(linha)-1]='\0';
		sscanf( linha, "%d %d", &a, &b ); 
		
		
		ia = contem( nos, a, &conta );
		ib = contem( nos, b, &conta );
		matAdj[ia][ib]= 1;				
		matAdj[ib][ia]= 1;				
		}

	imprimeGrafo(nos, (int *)matAdj, conta);

	return 0;
}






