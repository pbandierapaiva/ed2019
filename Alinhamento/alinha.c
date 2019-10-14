/* Arquivo: alinha.c
*
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *alinhaSW(char *, char *, int, int, int);
void imprime(char *, char *, int *);

int main() {
	int *matriz;
	char s1[] = "TGCA";
	char s2[] = "TGAA";
	
	matriz = alinhaSW(s1,s2, 5, -3, -4);
	imprime(s1,s2,matriz);
	return 0;
}

int *alinhaSW(char *s1, char *s2, int match, int mismatch, int gap) {
	int *S;
	int w,h;
	int max,cur;
	w = strlen(s2)+1;
	h = strlen(s1)+1;
	
	S = malloc( sizeof(int)*w*h );
	for(int x=0; x<w; x++)
		S[x]=0;
	for(int x=0; x<h; x++)
		S[x*w]=0;
	for(int i=1; i<h; i++) {
		for(int j=1; j<w; j++) {
			max = 0;
			cur = S[(i-1)*w+(j-1)];
			if( s1[ i ] == s2[ j ]) 
				cur = cur+match;
			else
				cur = cur+mismatch;
			if(cur>max)
				max=cur;			
			cur = S[i*w+(j-1)]+gap;
			if(cur>max)
				max=cur;
			cur = S[(i-1)*w+ j]+gap;
			if(cur>max)
				max=cur;
			S[i*w + j] =max;
		}
	}
	return S;
}

void imprime(char *s1, char *s2, int *S){
	int w;

	w = strlen(s2)+1;

	for(int j=0; j<strlen(s2); j++)
		printf("\t%c",s2[j]);
	for(int i=0; i<strlen(s1);i++) {
		printf("\n%c\t",s1[i]);
		for(int j=0; j<strlen(s2); j++)
			printf("%d\t", S[(i+1)*w + (j+1)]);           
	}
	printf("\n");
}






