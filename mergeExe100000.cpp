#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>

#define TAM 100000
#define _BSD_SOURCE

//Criando uma struct para os nós da lista duplamente encadeada, contendo o valor e o seu id
typedef struct no{
    int valor,id;
    struct no *next;
    struct no *prev;
}no;

typedef struct lista{
    int qtdNos;
    no *head;
    no *tail;
}lista;

lista *inicializaListaDE(){
    lista *listaDE = (lista*)malloc(sizeof(lista));
    
    listaDE->qtdNos = 0;
    listaDE->head = NULL;
    listaDE->tail = NULL;
   
    return listaDE;
}

void insere(lista *listaDE, int e){
    no *novo=(no*)malloc(sizeof(no));
   
    novo->valor=e;
    novo->id = listaDE->qtdNos+1;
    novo->prev = NULL;
    novo->next = NULL;
   
    if(listaDE->head == NULL){
        listaDE->qtdNos++;
        listaDE->head = novo;
        listaDE->tail = novo;
    }
    else{
        listaDE->qtdNos++;
        novo->prev = listaDE->tail;
        listaDE->tail->next = novo;
        listaDE->tail = novo;
    }
}

void imprime(lista *listaDE){
    no *nodo = listaDE->head;
    int i;
    printf("\n\n");
    for(i=0;i<listaDE->qtdNos;i++){
        printf("\t[%d]",nodo->valor);
        nodo = nodo->next;
    }
    /*printf("\n\n");
    nodo=listaDE->head;
    for(i=0;i<listaDE->qtdNos;i++){
        printf("\t[%d]",nodo->id);
        nodo=nodo->next;
    }*/
    printf("\n\n");
}

void copylist(lista *comeco, lista *local){
    int i;
    no *inicio=comeco->head;
    no *copia;
   
    for(i=0;i<comeco->qtdNos;i++){
        insere(local,inicio->valor);
        inicio = inicio->next;
    }
   
    copia = local->head;
    inicio = comeco->head;
   
    for(i=0;i<comeco->qtdNos;i++){
        copia->id=inicio->id;
        inicio = inicio->next;
        copia = copia->next;
    }
   
}


void divide(lista *listaDE, lista *E, lista *D){
    int i;
	int p = listaDE->head->id;
	int r = listaDE->tail->id,q;
    no *Q = listaDE->head;
   
    q = ((r - p)/2) + 1;
    for(i=0;i<=q-1;i++){
        Q = Q->next;
    }
    
    E->head = listaDE->head;
    E->qtdNos = q;
    E->tail = Q->prev;
   
    
    D->head=Q;
    D->qtdNos=(r-p)-(q-1);
    D->tail=listaDE->tail;
   
}

int Merge(lista *listaDE,lista *esquerda, lista *direita){
    no *esq;
    no *dir;
    no *list = listaDE->head;
    lista *E = inicializaListaDE();
    lista *D = inicializaListaDE();
    int i, cont = 0;
   
    copylist(esquerda, E);
    copylist(direita, D);
   
    esq=E->head;
    dir=D->head;
   
    insere(E, 99999);
    insere(D, 99999);
   
    for(i=0;i<listaDE->qtdNos;i++){
        if(esq->valor < dir->valor){
            list->valor=esq->valor;
            esq = esq->next;
            cont++;
        }
        else{
            list->valor = dir->valor;
            dir = dir->next;
            cont++;
        }
        list = list->next;
    }
   return cont;
}

int MergeSort(lista *listaDE, int p, int r){
	int cont;
    lista *listaEsq = inicializaListaDE();
    lista *listaDir = inicializaListaDE();
    if(r-p > 0){

        divide(listaDE,listaEsq,listaDir);
        MergeSort(listaEsq, listaEsq->head->id, listaEsq->tail->id);
        MergeSort(listaDir, listaDir->head->id, listaDir->tail->id);
        cont = Merge(listaDE, listaEsq, listaDir);
    }
	return cont;
}

int main(int argc,char *argv[]){
	clock_t Ticks;
	Ticks = clock();
	FILE *fileList;
    lista *list = inicializaListaDE(); 
    
    srand(time(NULL));
	char result;  
    int e, i , contador;
  	for(i=0;i<TAM;i++){
		e = rand()%1000000;
    	insere(list, e);
    }   
    
    contador = MergeSort(list, list->head->id, list->tail->id);
    imprime(list);
    
    printf("Operacoes:\n");
    printf("%d\n", contador);
    fclose(fileList);
    fileList = fopen( "mergeLista10000.txt", "wt");
    if (fileList != NULL) {
         
        if (result == EOF)
            printf("Erro ao gravar no arquivo");
    } else {
        printf("Erro ao abrir/criar o arquivo.");
    }
    
    Ticks = clock() - Ticks;
    double Tempo = ((double)Ticks)/((CLOCKS_PER_SEC/1000));
    printf("Tempo:");
    printf("\n%lf",Tempo);
    result = fprintf(fileList, "Tempo: %f\t",Tempo);
	result = fprintf(fileList, "Contador: %d\t",contador); 
}     
