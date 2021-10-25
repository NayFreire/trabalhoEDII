#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <limits.h>
#include <sys/time.h>

#define n 10000
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

int Aleatorio(elemento *vetorAux, int inicio, int meio, int fim){
	
	int i, auxV, pivoMediana;
	
	
/*while(meio < inicio || meio > fim){
		if(inicio > meio){
			auxV = meio;
			meio = inicio;
			inicio = auxV;
		}
		if(meio > fim){
			auxV = fim;
			fim = meio;
			meio = auxV;
		}
	}*/
	/*if(inicio > meio){
		auxV = meio;
		meio = inicio;
		inicio = auxV;
		printf("entrou aqui");
	}*/
/*	else if(meio > fim){
		auxV = fim;
		fim = meio;
		meio = auxV;
	}*/
	/*else if(inicio > fim){
		auxV = fim;
		fim = inicio;
		inicio = auxV;
	}*/
	
	printf("\n\nChegou os valores assim\n");
	printf("\n\t\tInicio = %d", inicio);
	printf("\n\t\tMeio = %d", meio);
	printf("\n\t\tFim 3 = %d", fim);
	
	printf("\n\nApos o if ficou assim\n");
	while(meio < inicio || meio > fim){
		if(inicio > meio){
			auxV = meio;
			meio = inicio;
			inicio = auxV;
		}
		if(meio > fim){
			auxV = fim;
			fim = meio;
			meio = auxV;
		}
	}	
	
	vetorAux[0].valor = inicio;
	vetorAux[1].valor = meio;
	vetorAux[2].valor = fim;
	
	printf("\n\nAgora o Vetor Aux Esta Assim\n");
	printf("\n\t\tVetAux Inicio = %d", vetorAux[0].valor);
	printf("\n\t\tVetAux Meio = %d", vetorAux[1].valor);
	printf("\n\t\tVetAux Fim 3 = %d", vetorAux[2].valor);
	
	/*printf("\n\t\tVetor Aux Ini %d", vetorAux[0].valor);
	printf("\n\t\tVetor Aux Mid = %d", vetorAux[1].valor);
	printf("\n\t\tVetor Aux Fim = %d", vetorAux[2].valor);
	
	/*for(i=0; i<3; i++){
		printf("\nVetor Aux Posicao [%d] = %d\n", i, vetorAux[i].valor);
	}*/
	
	//Se o valor 1 maior que o 2
	/*if(vetorAux[inicio].valor > vetorAux[meio].valor){
		auxV = vetorAux[meio].valor;
		vetorAux[meio].valor = vetorAux[inicio].valor;
		vetorAux[inicio].valor = auxV;
	}
	//Se o valor 2 maior que o 3
	else if(vetorAux[meio].valor > vetorAux[fim].valor){
		auxV = vetorAux[fim].valor;
		vetorAux[fim].valor = vetorAux[meio].valor;
		vetorAux[meio].valor = auxV;
	}
	//Se o valor 1 é maior que o 3
	else if(vetorAux[inicio].valor > vetorAux[fim].valor){
		auxV = vetorAux[fim].valor;
		vetorAux[fim].valor = vetorAux[inicio].valor;
		vetorAux[inicio].valor = auxV;
	}*/
	
	
	pivoMediana = meio;
	
/*	for(i=0; i<3; i++){
		printf("\nVetor Aux Ordenado [%d] = %d\n", i, vetorAux[i].valor);
	}*/
	printf("\n\nO pivo Mediana eh: %d\n\n", pivoMediana);
	
	return pivoMediana; //vetorAux[meio].valor;
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
	
	elemento vetorAux[3];
	
	int pivo_indice1 = (rand() % (fim - inicio + 1)) + inicio;
	int pivo_indice2 = (rand() % (fim - inicio + 1)) + inicio;
	int pivo_indice3 = (rand() % (fim - inicio + 1)) + inicio;
	
	printf("\nChegou aqui\n");
	/*printf("\n\t\tPivo_Indice 1 = %d", vetor[pivo_indice1].valor);
	printf("\n\t\tPivo_Indice 2 = %d", vetor[pivo_indice2].valor);
	printf("\n\t\tPivo_Indice 3 = %d", vetor[pivo_indice3].valor);*/
	
	printf("\n\t\tPivo_Indice 1 = %d", pivo_indice1);
	printf("\n\t\tPivo_Indice 2 = %d", pivo_indice2);
	printf("\n\t\tPivo_Indice 3 = %d", pivo_indice3);
	int pivo_indice = (Aleatorio(vetorAux, pivo_indice1, pivo_indice2, pivo_indice3));
	
	printf("\n\nO pivo indice retornado eh: %d\n\n", pivo_indice);
	troca(vetor, pivo_indice, fim);

	return Particiona(vetor, inicio, fim);
}

void QuickSort(elemento *vetor, int inicio, int fim){
	if(inicio < fim){
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
	
	for(i=0; i<n; i++){
		printf("%d\n", vetor[i].valor);
	}
	
	gettimeofday(&comeco, NULL);
	QuickSort(vetor, 0, tam_vet-1);
	gettimeofday(&final, NULL);
	
	printf("\n-----------------------------------------------\n");
	printf("Vetor Final Ordenado\n");
	
	for(i=0; i<n; i++){
		printf("%d\n", vetor[i].valor);
	}
	
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
	
	printf("\n\nNumero de Comparacoes: %d", counter);
	printf("\n\nTempo de processamento: %ld microsegundos\n\n", ((final.tv_sec - comeco.tv_sec)*1000000L+final.tv_usec) - comeco.tv_usec);
	
}
