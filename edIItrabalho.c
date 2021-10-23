#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 100

#include "ListaEncadeada.h"
#include "OrdenaMerge.h"

void main(){
    // int n = 10;
    int vetor[n];
    int inicio = 0;
    int fim = n-1;

    srand(time(NULL));

    for(int i=0;i<n;i++){
        vetor[i] = rand()%1000;
    }
    printf("\nINICIO DO VETOR DESORDENADO\n");
    for(int i=0;i<n;i++){
        printf("%d\n", vetor[i]);
    }
    printf("\nFIM DO VETOR DESORDENADO\n");
    mergeSort(vetor, inicio, fim);

    printf("\n*** Ordenado ***\n");
    for(int i=0;i<n;i++){
        printf("%d\n", vetor[i]);
    }

    printf("Comparacoes: %d\n", counter);

    criaLista();
    for(int i=0;i<10;i++){
        insereInicio(rand()%1000);
    }
    imprimeLista();
}
