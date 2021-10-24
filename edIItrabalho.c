#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define n 100

#include "ListaEncadeada.h"
#include "OrdenaMerge.h"

struct timeval comeco, final;

void main(){
    // int n = 10;
    int vetor[n];
    int inicio = 0;
    int fim = n-1;

    FILE *fileList;

    srand(time(NULL));

    for(int i=0;i<n;i++){
        vetor[i] = rand()%1000;
    }
    printf("\nINICIO DO VETOR DESORDENADO\n");
    for(int i=0;i<n;i++){
        printf("%d\n", vetor[i]);
    }
    printf("\nFIM DO VETOR DESORDENADO\n");

    gettimeofday(&comeco, NULL);
    mergeSort(vetor, inicio, fim);
    gettimeofday(&final, NULL);

    printf("\n*** Ordenado ***\n");
    for(int i=0;i<n;i++){
        printf("%d\n", vetor[i]);
    }

    criaLista();
    for(int i=0;i<10;i++){
        insereInicio(rand()%1000);
    }
    imprimeLista();
    //Elemento *listaD = imprimeListaEncadeada();
    //mergeSortLista(listaD, 0, tamanho-1);
    imprimeListaD();

    printf("Comparacoes: %d\n", counter);
    printf("Tempo de processamento: %ld microsegundos\n\n", ((final.tv_sec - comeco.tv_sec)*1000000L+final.tv_usec) - comeco.tv_usec);
}
