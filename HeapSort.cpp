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

//Função CriaHeap
int CriaHeap(elemento *vetor, int i, int f){
	int aux=0, j=0;
	aux = vetor[i].valor;
	j = i * 2 + 1;
	
	while(j <= f){
		if(j < f){
			if(vetor[j].valor < vetor[j+1].valor){
				j++;
			}
		}
		if(aux < vetor[j].valor){
			vetor[i].valor = vetor[j].valor;
			i = j;
			j = i * 2 + 1;
			numComparacoes();	
		} 
		else{
			j = f + 1;	
		}
	}
	vetor[i].valor = aux;
}

//Função HeapSort
int heapSort(elemento *vetor){
	int i=0, aux=0;
	
	for(i=(n-1)/2; i>=0; i--){
		CriaHeap(vetor, i, n-1);		
	}
	for(i=n-1; i>=1; i--){
		aux = vetor[0].valor;
		vetor[0].valor = vetor[i].valor;
		vetor[i].valor = aux;
		CriaHeap(vetor, 0, i-1);
	}
}

//Main
int main(){
	
	FILE *fileList;
	clock_t Ticks;
	Ticks = clock();
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
		
	//Chamada da função heap e funcoes de tempo
	gettimeofday(&comeco, NULL);
	heapSort(vetor);
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
    fileList = fopen("HeapSort.txt", "wt");
    if(fileList != NULL){
        if(result == EOF){
            printf("Erro ao gravar no arquivo");
    	}
    }
	else{
        printf("Erro ao abrir/criar o arquivo");
    }
    
    //Escrever no arquivo os resultados
    result = fprintf(fileList, "  HeapSort		N: %d\n", n);
    result = fprintf(fileList, "\n  Microsegundos:	%ld", ((final.tv_sec - comeco.tv_sec)*1000000L+final.tv_usec) - comeco.tv_usec);
	result = fprintf(fileList, "\n  Comparações:		%d", counter); 
}

