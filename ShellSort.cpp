#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <limits.h>
#include <sys/time.h>

#define n 500000
#define _BSD_SOURCE

//Struct Tempo
struct timeval comeco, final;

//Struct Elemento
typedef struct elemento Elemento;
struct elemento{
	int valor;
};

//Função para o Numero de Comparações
int counter=0;
void numComparacoes(){
    counter++;
}

//Função para Gerar Numero Aleatorio
void NumeroAleatorio(elemento *vetor){
	int i=0;
	
	srand((unsigned)time(NULL));
	
	for(i=0; i<n; i++){
		vetor[i].valor = 1 + rand() % 100000000 * rand() % 100000000 + rand() % 100000000 - rand() % 100000000 * rand() % n;
	}
}

//Função Shell Sort
void shellSort(elemento *vetor, int tam){
    int i, j, valor;
 
    int h = 1;
    while(h < tam){
        h = 3 * h + 1;
    }
    while(h > 0){
        for(i = h; i < tam; i++){
            valor = vetor[i].valor;
            j = i;
            while(j > h-1 && valor <= vetor[j - h].valor){
            	numComparacoes();
                vetor[j].valor = vetor[j - h].valor;
                j = j - h;
            }
            vetor[j].valor = valor;
        }
        h = h/3;
    }
}

//Main
int main(){
	
	FILE *fileList;
	char result;
	
	int i;
	elemento vetor[n];
	
	srand(time(NULL));
	
	NumeroAleatorio(vetor);
	
	printf("Vetor Inicial Desordenado");
	
	/*
	//Apresentar vetor desordenado
	for(i=0; i<n; i++){
		printf("%d\n", vetor[i].valor);
	}
	*/
	
	//Chamada da função Shell e funcoes de tempo
	gettimeofday(&comeco, NULL);
	shellSort(vetor, n);
	gettimeofday(&final, NULL);
	
	printf("\n-----------------------------------------------\n");
	printf("Vetor Final Ordenado");
	
	printf("\n-----------------------------------------------\n");
	printf("Resultado exportado no arquivo");
	
	/*
	//Apresentar vetor ordenado
	for(i=0; i<n; i++){
		printf("%d\n", vetor[i].valor);
	}
	*/
	
	/*
	//Printf com numero de comparacoes e tempo
	printf("Numero de Comparacoes: %d", counter);
	printf("\n\nTempo de processamento: %ld microsegundos\n\n", ((final.tv_sec - comeco.tv_sec)*1000000L+final.tv_usec) - comeco.tv_usec);
	*/
	
	//fclose(fileList);
    fileList = fopen("ShellSort.txt", "wt");
    if(fileList != NULL){
        if(result == EOF){
            printf("Erro ao gravar no arquivo");
    	}
    }
	else{
        printf("Erro ao abrir/criar o arquivo");
    }
    
    //Escrever no arquivo os resultados
    result = fprintf(fileList, "  ShellSort		N: %d\n", n);
    result = fprintf(fileList, "\n  Microsegundos:	%ld", ((final.tv_sec - comeco.tv_sec)*1000000L+final.tv_usec) - comeco.tv_usec);
	result = fprintf(fileList, "\n  Comparações:		%d", counter); 
}
