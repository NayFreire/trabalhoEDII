#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <limits.h>
#include <sys/time.h>

#define n 1000
#define _BSD_SOURCE

//Struct Tempo
struct timeval comeco, final;

//Função para o Numero de Comparações
int counter = 0;
void numComparacoes(){
    counter++;
}

//Função para Gerar Numero Aleatorio
void NumeroAleatorio(int *vetor){
	int i=0;
	
	srand((unsigned)time(NULL));
	
	for(i=0; i<n; i++){
		vetor[i] = 1 + rand() % 100000000 * rand() % 100000000 + rand() % 100000000 - rand() % 100000000 * rand() % n;
	}
}

//Função Shell Sort
void shellSort(int *vetor, int tam) {
    int i, j, valor;
 
    int h = 1;
    while(h < tam) {
        h = 3*h+1;
    }
    while (h > 0) {
        for(i = h; i < tam; i++) {
            valor = vetor[i];
            j = i;
            while (j > h-1 && valor <= vetor[j - h]) {
            	numComparacoes();
                vetor[j] = vetor[j - h];
                j = j - h;
            }
            vetor[j] = valor;
        }
        h = h/3;
    }
}

//Main
int main(){
	int vetor[n];
	int i;
	
	srand(time(NULL));
	
	NumeroAleatorio(vetor);
	
	printf("vetoror Inicial Desordenado\n");
	
	//Apresentar vetor desordenado
	for(i=0; i<n; i++){
		printf("%d\n", vetor[i]);
	}
	
	printf("\n\n-----------------------------------------------\n\n");
	
	
	//Chamada da função Shell e funcoes de tempo
	gettimeofday(&comeco, NULL);
	shellSort(vetor, n);
	gettimeofday(&final, NULL);
	
	printf("vetor Final Ordenado\n");
	
	//Apresentar vetor ordenado
	for(i=0; i<n; i++){
		printf("%d\n", vetor[i]);
	}
	
	printf("\n\n-----------------------------------------------\n\n");
	
	//Printf com numero de comparacoes e tempo
	printf("Numero de Comparacoes: %d", counter);
	printf("\n\nTempo de processamento: %ld microsegundos\n\n", ((final.tv_sec - comeco.tv_sec)*1000000L+final.tv_usec) - comeco.tv_usec);
}
