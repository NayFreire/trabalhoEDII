#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 10

void mergeSort(int vetor[], int inicio, int meio){
  for(int i=0;i<n;i++){
    printf("%d\n", vetor[i]);
  }
  printf("\n----------------------------------------\n");
  // printf("%d, %d, %d", inicio, meio, fim);
  int tamanho = fim - inicio + 1;
  int temp[n], fim1 = 0, fim2 = 0;
  int p1 = inicio, p2 = meio + 1;

  // temp = (int*) malloc(tamanho * sizeof(int));

  for(int i=0;i<tamanho;i++){
    if(!fim1 && !fim2){
      printf("%d - %d < %d - %d\n", p1, vetor[p1], p2, vetor[p2]);
      if(vetor[p1] < vetor[p2]){
        temp[i] = vetor[p1];
        p1++;
        printf("temp1[%d] = %d\n", i, temp[i]);
      }
      else{
        if(!fim1){
          temp[i] = vetor[p2];
          p2++;
          printf("temp2[%d] = %d\n", i, temp[i]);
        }
      }

      if(p1>meio){
        fim1 = 1;
      }
      if(p2>fim){
        fim2 = 1;
      }
    }
    else{
      if(!fim1){
        temp[i] = vetor[p1++];
      }
      else{
        temp[i] = vetor[p2++];
      }
    }
  }
  /* for(int j=0;j<tamanho-1;j++){
    for(int k=inicio;k<fim;k++){
      vetor[k] = temp[j];
    }
  } */
  printf("ordenado\n");
  for(int i=0;i<n;i++){
    printf("%d\n", temp[i]);
  }
}

void main(){
  // int n = 10;
  int vetor[n];
  int inicio = 1;
  int fim = n-1;
  int meio = (inicio+fim)/2;

  srand(time(NULL));

  for(int i=0;i<n;i++){
    vetor[i] = rand()%1000;
  }

  /* for(int i=0;i<n;i++){
    printf("%d\n", vetor[i]);
  } */

  mergeSort(vetor, inicio, meio);
  mergeSort(vetor, meio + 1, fim);
}
