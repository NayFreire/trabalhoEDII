#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <limits.h>
#include <sys/time.h>

#define n 100000
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

//Função que realiza a troca entre dois elementos
void troca(elemento *vetor, int i, int j){
	int aux = vetor[i].valor;
	vetor[i].valor = vetor[j].valor;
	vetor[j].valor = aux;
}

//Particiona e retorna o índice do pivô
int Particiona(elemento *vetor, int inicio, int fim){
	int pivo, pivo_indice, i;
	
	pivo = vetor[fim].valor;
	pivo_indice = inicio;
	
	for(i = inicio; i < fim; i++){
		if(vetor[i].valor <= pivo){
			numComparacoes();
			
			troca(vetor, i, pivo_indice);

			pivo_indice++;
		}
	}
	
	troca(vetor, pivo_indice, fim);
	
	return pivo_indice;
}

int ParticionaRandom(elemento *vetor, int inicio, int fim){
	int i;
	
	int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;
	
	troca(vetor, pivo_indice, fim);

	return Particiona(vetor, inicio, fim);
}

void QuickSort(elemento *vetor, int inicio, int fim){
	if(inicio < fim)
	{
		// função particionar retorna o índice do pivô
		int pivo_indice = ParticionaRandom(vetor, inicio, fim);
		
		// chamadas recursivas quick_sort
		QuickSort(vetor, inicio, pivo_indice - 1);
		QuickSort(vetor, pivo_indice + 1, fim);
	}
}

void NumeroAleatorio(elemento *vetor){
	int i=0;
	
	srand((unsigned)time(NULL));
	
	for(i=0; i<n; i++){
		vetor[i].valor = 1 + rand() % 100000000 * rand() % 100000000 + rand() % 100000000 - rand() % 100000000 * rand() % n;
	}
}

int main(){
	
	FILE *fileList;
	char result;
	
	elemento vetor[n];
	NumeroAleatorio(vetor);
	
	int tam_vet = sizeof(vetor) / sizeof(int);
	int i;
	
	srand(time(NULL));
	
	printf("Vetor Inicial Desordenado");
	
	/*for(i=0; i<n; i++){
		printf("%d\n", vetor[i].valor);
	}*/
	
	gettimeofday(&comeco, NULL);
	QuickSort(vetor, 0, tam_vet-1);
	gettimeofday(&final, NULL);
	
	printf("\n-----------------------------------------------\n");
	printf("Vetor Final Ordenado");
	
	/*for(i=0; i<n; i++){
		printf("%d\n", vetor[i].valor);
	}*/
	
	printf("\n-----------------------------------------------\n");
	printf("Resultado exportado no arquivo");
	
		//fclose(fileList);
    fileList = fopen("QuickSort_Aleatorio.txt", "wt");
    if(fileList != NULL){
        if(result == EOF){
            printf("Erro ao gravar no arquivo");
    	}
    }
	else{
        printf("Erro ao abrir/criar o arquivo");
    }
    
    //Escrever no arquivo os resultados
    result = fprintf(fileList, "  QuickSort_Aleatorio		N: %d\n", n);
    result = fprintf(fileList, "\n  Microsegundos:	%ld", ((final.tv_sec - comeco.tv_sec)*1000000L+final.tv_usec) - comeco.tv_usec);
	result = fprintf(fileList, "\n  Comparações:		%d", counter); 
	
	/*printf("Numero de Comparacoes: %d", counter);
	printf("\n\nTempo de processamento: %ld microsegundos\n\n", ((final.tv_sec - comeco.tv_sec)*1000000L+final.tv_usec) - comeco.tv_usec);*/
	
}
