/*
* Programa: consulta-dl.c
*
* Busca nome em arquivo indexado, recupera registro, cronometra o tempo de busca
*
* Utiliza índice em uma lista duplamente encadeada alocada dinamicamente em memória ListaDL
*
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>   	// para toupper()
#include <time.h>	// para clock()

#include "cadastro.h"	// Estrutura do cadastro
#include "listadl.h"	// Estrutura e protótipos de função para lista duplamente ligada
#include "cadutil.h"

int main() {
	char nomebusca[100];
	Cadastro registro;
	long int i;
	//long int vetor[1000000];

	struct ListaDL raizResultadoBusca, *pdl, raizIndice;

	strcpy(raizResultadoBusca.nome,"NO RAIZ");
	raizResultadoBusca.indice=0;
	raizResultadoBusca.proximo=NULL; // Lista vazia
	raizResultadoBusca.anterior=NULL;
	strcpy(raizIndice.nome,"NO RAIZ");
	raizIndice.indice=0;
	raizIndice.proximo=NULL; // Lista vazia
	raizIndice.anterior=NULL;

	char *p;
	clock_t inicio, fimBusca, fimOrdena;

	FILE *fp, *ndxfp;

	// Abre arquivos de dados
	if( !(fp = fopen("../data/cadstru.arq","r")) ) {
		printf("Erro ao abrir arquivo de dados.\n");
		return 1;
		}
	// Carrega índice em lista duplamente ligada - ListaDL
	printf("Registros carregados em lista duplamente ligada: %ld\n",
		carregaIndice("../data/cadstru.ndx", &raizIndice) );

	// Inicia Interface com o usuário
	while(1) {
		printf("Entre com nome para busca (Ctrl+C termina): ");
		fgets( nomebusca, 100, stdin);

		// transforma o string para maiúsculas e o \n em \0
		p = nomebusca;
		while( *p!='\0' && *p!='\n') {
			*p = toupper(*p);
			p++;
			}
		*p = '\0';


		inicio = clock(); // INICIA CRONOMETRO


		i =  buscaNome( nomebusca, raizIndice, &raizResultadoBusca );

		fimBusca = clock(); // CRONOMETRO - final da busca

		if( i==0 ){ // Não encontrado
			printf("\nRegistro não encontrado\n\n");
			continue;
			}
		// Ordena resultado
		ordenaDL(&raizResultadoBusca );
		fimOrdena =  clock(); // PARA CRONOMETRO Final da ordenação


		pdl = raizResultadoBusca.proximo;
		while(pdl) {
			pegaRegPorIndex(&registro, fp, pdl->indice);
//			printf("Nome: \t%s Lotação: \t%s Cargo: \t%s\n",
//					registro.NOME, registro.UORG_LOTACAO, registro.DESCRICAO_CARGO);
			printf("Nome: \t%s\n",registro.NOME);

			pdl = pdl->proximo;

			}

		printf("Número de ocorrências encontradas: %ld\n",i);
		printf("Tempo de consulta %f s\n", (double)(fimBusca - inicio) / CLOCKS_PER_SEC);
		printf("Tempo para ordenar %f s\n", (double)(fimOrdena - fimBusca) / CLOCKS_PER_SEC);

		}

	return 0;
}
