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

int Particiona(elemento *vetor, int inicio, int fim){
	int esq, dir;
	elemento aux, pivo;
	
	esq = inicio;
	dir = fim;
	pivo = vetor[inicio];
	while(esq < dir){
		while(vetor[esq].valor<= pivo.valor){
			esq++;
			numComparacoes();
		}
		while(vetor[dir].valor > pivo.valor){
			dir--;
		}
		if(esq < dir){
			aux = vetor[esq];
			vetor[esq] = vetor[dir];
			vetor[dir] = aux;
		}
	}
	
	vetor[inicio] = vetor[dir];
	vetor[dir] = pivo;
	
	return dir;
}

int QuickSort(elemento *vetor, int inicio, int fim){ //ORDENACAO QUICK SORT QUE PRECISA DO PARTICIONA PRIMEIRO
	int pivo;
	
	if(fim > inicio){
		pivo = Particiona(vetor, inicio, fim);
		QuickSort(vetor, inicio, pivo-1);
		QuickSort(vetor, pivo+1, fim);
	}
	
}

//Main
int main(){
	
	elemento vetor[n];
	
	FILE *fileList;
	char result;
	
	int i;
	
	
	srand(time(NULL));
	
	NumeroAleatorio(vetor);
	
	printf("Vetor Inicial Desordenado");
	
	//Apresentar vetor desordenado
	/*
	for(i=0; i<n; i++){
		printf("%d\n", vetor[i].valor);
	}
	*/
		
	//Chamada da função heap e funcoes de tempo
	gettimeofday(&comeco, NULL);
	QuickSort(vetor, 0, n-1);
	gettimeofday(&final, NULL);
	
	printf("\n-----------------------------------------------\n");
	printf("Vetor Final Ordenado");
	
	printf("\n-----------------------------------------------\n");
	printf("Resultado exportado no arquivo");
	
	/*	
	//Apresentar vetor ordenado
	for(i=0; i<n; i++){
		printf("%d\n", vetor[i].valor);
	}*/
	
	//Printf com numero de comparacoes e tempo
	/*
	printf("Numero de Comparacoes: %d", counter);
	printf("\n\nTempo de processamento: %ld microsegundos\n\n", ((final.tv_sec - comeco.tv_sec)*1000000L+final.tv_usec) - comeco.tv_usec);
	*/
	
	//fclose(fileList);
    fileList = fopen("QuickSort_Recursivo.txt", "wt");
    if(fileList != NULL){
        if(result == EOF){
            printf("Erro ao gravar no arquivo");
    	}
    }
	else{
        printf("Erro ao abrir/criar o arquivo");
    }
    
    //Escrever no arquivo os resultados
    result = fprintf(fileList, "  QuickSort		N: %d\n", n);
    result = fprintf(fileList, "\n  Microsegundos:	%ld", ((final.tv_sec - comeco.tv_sec)*1000000L+final.tv_usec) - comeco.tv_usec);
	result = fprintf(fileList, "\n  Comparações:		%d", counter); 
}
