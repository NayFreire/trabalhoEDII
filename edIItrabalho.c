#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 10

void merge(int vetor[], int inicio, int meio, int fim){
  for(int i=0;i<n;i++){
    printf("%d\n", vetor[i]);
  }
  printf("\n----------------------------------------\n");

  int tamanho = fim - inicio + 1;
  int fim1 = 0, fim2 = 0;
  int p1 = inicio, p2 = meio + 1;

  int *temp = (int*) malloc(tamanho * sizeof(int));

  for(int i=0;i<=tamanho-1;i++){
    if(!fim1 && !fim2){
      if(vetor[p1] < vetor[p2]){
        temp[i] = vetor[p1];
        p1++;
      }
      else{
        temp[i] = vetor[p2];
        p2++;
      }

      if(p1 > meio){
        fim1 = 1;
      }
      if(p2 > fim){
        fim2 = 1;
      }
    }
    else{
      if(!fim1){
        temp[i] = vetor[p1];
        p1++;
      }
      else{
        temp[i] = vetor[p2];
        p2++;
      }
    }
  }
  for(int j=0, k=inicio;j<=tamanho-1;j++,k++){
      vetor[k] = temp[j];
      printf("%d - ", temp[j]);
  }
}

int mergeSort(int vetor[], int inicio, int fim){
  if(inicio < fim){
      int meio = (inicio+fim)/2;
      mergeSort(vetor, inicio, meio);
      mergeSort(vetor, meio + 1, fim);
      merge(vetor, inicio, meio, fim);
  }
}

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
}
