/* Arquivo: alinha.c
*
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *geraMatrizSW(char *, char *, int, int, int);
void imprime(char *, char *, int *);
int *maxValPtr(int *, int, int);

int main() {
	int *matriz;
	int s1len, s2len;
	int nrow, ncol;

//	char s1[] = "TGCACT";
//	char s2[] = "TGAG";
	
	char s1[] = "TGCACAGACTACGGAGCATCGACGGACTAGCAGCACTAGCT";
	char s2[] = "TGAAACTACGGAGCATCGACGGACTAGCTGAGGCATTCAGCAG";
//	char s1[] = "MNGTEGPDFYVPFSNATGVVRSPFEYPQYYLAEPWQFSMLAAYMFLLIVLGFPINFLTLYVTVQHKKLRTPLNYILLNLAVADLFMVFGGFTTTLYTSLHGYFVFGPTGCNIEGFFATLGGEIALWSLVVLAIERYVVVCKPMSNFRFGENHAIMGVAFTWVMALACAAPPLVGWSRYIPEGMQCSCGVDYYTLKPEVNNESFVIYMFVVHFTIPLIVIFFCYGQLVFTVKEAAAQQQESATTQKAEKEVTRMVILMVVFFLICWVPYASVAFYIFTHQGSNFGPIFMTLPAFFAKSSSIYNPVIYIMMNKQFRNCMLTTLCCGKNPLGDDEASATASKTETSQVAPA";
//	char s2[] = "MNGTEGLNFYVPFSNKTGVVRSPFEYPQYYLAEPWQFSVLAAYMFLLIVLGFPINFLTLYVTVQHKKLRTPLNYILLNLAVANLFMVFGGFTTTLYTSLHAYFIFGPTGCNLEGFFATLGGEIALWSLVVLAIERYVVVCKPMSNFRFGENHAIMGLALTWIMAMACAAPPLVGWSRYIPEGMQCSCGIDYYTLSPEVNNESFVIYMFVVHFTIPLVIIFFCYGQLVFTVKEAAAQQQESATTQKAEKEVTRMVIIMVVAFLICWVPYASVAFYIFTHQGSDFGPIFMTIPSFFAKSSSIYNPVIYIMMNKQFRNCMLTTLCCGRNPLGDDEASTTASKTETSQVAPA";
	s1len = strlen(s1);
	s2len = strlen(s2);
	nrow = s1len+1;
	ncol = s2len+1;
	matriz = geraMatrizSW(s1,s2, 5, -3, -4);


//	imprime(s1,s2,matriz);
	
	return 0;
}

int *traceback(int *S, int nlin, int ncol){
		//char aln1[nlin+ncol], aln2[nlin+ncol];
		int vetorDesloc[nlin+ncol];
		int *p;
		int i=0;
		int *ps,*pe,*pd, *max;
		
		p = maxValPtr( S, nlin, ncol);
		while( *p ) {
			vetorDesloc[i]=p-S;
			
			ps = (p-ncol); //superior
			pe = (p-1); // esquerda
			pd = (p-ncol-1); // diagonal
			if(pd<S) break;
			if( *ps > *pe)
			 	max=ps;
			else
				max=pe;
			if(*pd >= *max)
				max=pd;
			p=max;
						
		} 
		
		return vetorDesloc;
} 

int *maxValPtr(int *S, int nlin, int ncol){
 	int *p, *maxp;
	int maxVal=0;
 
 	maxVal = *S;
 	for(p=S, maxp=S; p-S < nlin*ncol; p++ ) {
	 	if( *p>=maxVal ) {
			maxVal=*p;
			maxp=p;
			}
		}
	return maxp;
}

int *geraMatrizSW(char *s1, char *s2, int match, int mismatch, int gap) {
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
			if( s1[ i-1 ] == s2[ j-1 ]) 
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






