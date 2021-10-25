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

void Trocar(elemento *vetor, int i, int j){
	int aux = vetor[i].valor;
	vetor[i].valor = vetor[j].valor;
	vetor[j].valor = aux;
}

int Particiona(elemento *vetor, int inicio, int fim){
	
	/*int k1select = rand() % sizeof(vetor);
	int k2select = rand() % sizeof(vetor);
	int k3select = rand() % sizeof(vetor);
	
	printf("\n\nValores aleatorios escolhidos: K1 = %d, K2 = %d, K3 = %d\n\n", vetor[k1select].valor, vetor[k2select].valor, vetor[k3select].valor);*/
	
	int meio = (inicio + fim) / 2;
	int k1, k2, k3;
	k1 = vetor[inicio].valor;
	k2 = vetor[meio].valor;
	k3 = vetor[fim].valor;
	
	/*printf("\nValores k1 = %d, k2 = %d, k3 = %d", k1, k2, k3);*/
	
	int medianaIndice=0;
	
	if(k1 < k2){
		numComparacoes();
		if(k2<k3){
			medianaIndice = meio;
		}
		else{
			if(k1 < k3){
				medianaIndice = fim;
			}
			else{
				medianaIndice = inicio;
			}
		}
	}
	else{
		numComparacoes();
		if(k3 < k2){
			medianaIndice = meio;
		}
		else{
			medianaIndice = inicio;
		}
	}
	Trocar(vetor, medianaIndice, fim);
	
	int pivo = vetor[fim].valor;
	int i = inicio - 1;
	int j;
	
	for(j=inicio; j<=fim-1; j++){
		if(vetor[j].valor <= pivo){
			i = i+1;
			Trocar(vetor, i, j);
		}
	}
	Trocar(vetor, i+1, fim);
	
	return i+1;
}

int QuickSortMediana(elemento *vetor, int inicio, int fim){
	int pivo;
	
	if(fim > inicio){
		pivo = Particiona(vetor, inicio, fim);
		QuickSortMediana(vetor, inicio, pivo-1);
		QuickSortMediana(vetor, pivo+1, fim);
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
	
	/*for(i=0; i<n; i++){
		printf("%d\n", vetor[i].valor);
	}*/
	
		
	//Chamada da função heap e funcoes de tempo
	gettimeofday(&comeco, NULL);
	QuickSortMediana(vetor, 0, n-1);
	gettimeofday(&final, NULL);
	
	printf("\n-----------------------------------------------\n");
	printf("Vetor Final Ordenado");
	
	printf("\n-----------------------------------------------\n");
	printf("Resultado exportado no arquivo");
	
		
	//Apresentar vetor ordenado
	/*for(i=0; i<n; i++){
		printf("%d\n", vetor[i].valor);
	}*/
	
	//Printf com numero de comparacoes e tempo
	
	//printf("\n\nNumero de Comparacoes: %d", counter);
	//printf("\n\nTempo de processamento: %ld microsegundos\n\n", ((final.tv_sec - comeco.tv_sec)*1000000L+final.tv_usec) - comeco.tv_usec);
	
	
	//fclose(fileList);
    fileList = fopen("QuickSort_Mediana.txt", "wt");
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
