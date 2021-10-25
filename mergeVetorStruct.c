#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define n 100

struct timeval comeco, final;

typedef struct pessoa{
    int chave;
    char nome;
    char endereco;
    char nomeMae;
    char nomePai;
    int cadastroAtivo;
    float altura;
    float peso;
    float imc;
    float nota;
    struct no *next;
    struct no *prev;
}pessoa;

char criaStrings (){
	char alfabeto[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	int i, selecionada;
	char cadeia[200];
	//printf("\nentrou na string %c\n", alfabeto[0]);
	
	for(i=0;i<200;i++){
		selecionada = rand()%sizeof(alfabeto);
		//printf("select: %d\n", selecionada);
		cadeia[i] = (char) alfabeto[selecionada];
	}
	//for(i=0;i<200;i++){
		printf("%s", cadeia);
	//}
	return cadeia[200];
}

void main(){
    // int n = 10;
    pessoa* vetor = (pessoa*)malloc(sizeof(pessoa) * n);
    int inicio = 0;
    int fim = n-1;

    FILE *fileList;

    srand(time(NULL));
	int i;
    for(i=0;i<10;i++){
    	printf("entrou[%d]\n", i);
    	vetor[i].chave = rand()%1000000*i;
    	printf("chave[%d] = %d\n", i, vetor[i].chave);
    	vetor[i].nome = "dhfghfgnfgnfgn";
    	printf("nome[%d] = %c",i , vetor[i].nome);
    	/*vetor[i].nomeMae = criaStrings(cadeia);
    	vetor[i].nomePai = criaStrings(cadeia);
    	vetor[i].endereco = criaStrings(cadeia);
    	vetor[i].cadastroAtivo = 1;
    	vetor[i].altura = rand()%2;
    	vetor[i].peso = rand()%100;
    	vetor[i].imc = rand()%40;
    	vetor[i].nota = rand()%10;*/
    }
    //printf("\nINICIO DO VETOR DESORDENADO\n");
    for(i=0;i<n;i++){
        printf("nome: %s", vetor[i].nome);
    }
    //printf("\nFIM DO VETOR DESORDENADO\n");

    gettimeofday(&comeco, NULL);
    //mergeSort(vetor, inicio, fim);
    gettimeofday(&final, NULL);

    //printf("\n*** Ordenado ***\n");
    for(i=0;i<n;i++){
        //printf("%d\n", vetor[i]);
    }

    /*criaLista();
    for(i=0;i<10;i++){
        insereInicio(rand()%1000000);
    }
    //Elemento *listaD = imprimeListaEncadeada();
    //mergeSortLista(listaD, 0, tamanho-1);
    imprimeListaD();
    imprimeListaE();*/

    /*printf("Número de valores: %d \nComparacoes: %d\n", n, counter);
    printf("Tempo de processamento do vetor: %ld microsegundos\n\n", ((final.tv_sec - comeco.tv_sec)*1000000L+final.tv_usec) - comeco.tv_usec);
	*/
}
