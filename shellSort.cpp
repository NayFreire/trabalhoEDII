#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <limits.h>
#include <sys/time.h>

#define n 100000
#define _INT_MAX +2147483647
#define qtdbuscas 10000000
#define ms 1000000 
#define _BSD_SOURCE

//Struct Tempo
struct timeval comeco, final;

//Numero de Comparações
int counter = 0;
void numComparacoes(){
    counter++;
}

//Gerar Codigo Aleatorio
void CodigoAleatorio(int *vet){
	int i=0;
	
	srand((unsigned)time(NULL));
	
	for(i=0; i<n; i++){
		vet[i] = 1 + rand() % 100000000000000 * rand() % 100000000000000 + rand() % 100000000000000 - rand() % 100000000 * rand() % n;
	}
	
	//vet[i] = 1 + rand() % 100000000000000 * rand() % 100000000000000 + rand() % 100000000000000 - rand() % 100000000 * rand() % n;
}


//Shell Sort
void shellSort(int *vet, int tam) {
    int i, j, valor;
 
    int h = 1;
    while(h < tam) {
        h = 3*h+1;
    }
    while (h > 0) {
        for(i = h; i < tam; i++) {
            valor = vet[i];
            j = i;
            while (j > h-1 && valor <= vet[j - h]) {
            	numComparacoes();
                vet[j] = vet[j - h];
                j = j - h;
            }
            vet[j] = valor;
        }
        h = h/3;
    }
}

int main(){
	int vet[n];
	int i;
	
	srand(time(NULL));
	
	CodigoAleatorio(vet);
	
	printf("Vetor Inicial Desordenado\n");
	
	//Apresentar vetor desordenado
	for(i=0; i<n; i++){
		printf("\t%d", vet[i]);
	}
	
	printf("\n\n-----------------------------------------------\n\n");
	
	//Chamada da função
	gettimeofday(&comeco, NULL);
	shellSort(vet, n);
	gettimeofday(&final, NULL);
	
	printf("Vetor Final Ordenado\n");
	
	//Apresentar vetor ordenado
	for(i=0; i<n; i++){
		printf("\t%d", vet[i]);
	}
	
	printf("\n\n-----------------------------------------------\n\n");
	
	printf("Numero de Comparacoes: %d", counter);
	printf("\n\nTempo de processamento: %ld microsegundos\n\n", ((final.tv_sec - comeco.tv_sec)*1000000L+final.tv_usec) - comeco.tv_usec);
}
