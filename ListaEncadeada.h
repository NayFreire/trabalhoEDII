#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define max 100000
#define _BSD_SOURCE

//#include "OrdenaMergeLista.h"

struct timeval begin, end;

typedef struct elemento Elemento;
struct elemento {
	int valor;
	Elemento *proximo;
	Elemento *anterior;
};
//Criar 2 variáveis globais.
Elemento *inicio;
Elemento *fim;
int tamanho;

// Criando prototipos de função
void criaLista();
Elemento *aloca(int valor);
void insereInicio(int valor);
void insereFim(int valor);
void inserePosicao(int valor, int posicao);
void removeInicio();
void removeFim();
void imprimeLista();
void imprimeListaContrario();

//Criar 2 elemmentos nulos na lista.
void criaLista() {
	inicio = NULL;
	fim = NULL;
	tamanho = 0;
}
//Alocar um dado, e como funciona o esquema do lista duplamente encadeada:
Elemento *aloca(int valor) {
	Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
	novo->valor = valor;
	novo->anterior = NULL;
	novo->proximo = NULL;
	return novo;
}

void removeInicio() {
	Elemento *atual = inicio;
	inicio = atual->proximo;
	inicio->anterior = NULL;
	tamanho--;
}
void removeFim() {
	Elemento *atual = fim;
	fim = atual->anterior;
	fim->proximo = NULL;
	tamanho--;
}

//Inserir no inicio da lista:
void insereInicio(int valor) {
	Elemento *novo = aloca(valor);   //criar novo elemento
	//verificar se o inicio for nulo, se sim, inicio recebe novo e o fim vai ser novo também, pois se os dois são nulos o inico e fim recebe o novo.
	if(inicio==NULL){
		inicio=novo;
		fim=novo;

	//Se a lista já tiver dado se cria outro elemento e aponta o ant para o dado 2 e prox do dado 2 para o 1.
	}else{
		Elemento *atual; //criar novo elemento caso tenha dado no inicio da lista.
		atual = inicio;
		novo->proximo = atual;
		atual->anterior = novo;
		inicio = novo;
	}
	tamanho++;
}

//Inserir no fim da lista:
void insereFim(int valor) {
	Elemento *novo = aloca(valor);   //criar novo elemento
	//verificar se o inicio for nulo, se sim, inicio recebe novo e o fim vai ser novo também, pois se os dois são nulos o inico e fim recebe o novo.
	if(inicio==NULL){
		inicio=novo;
		fim=novo;
	//Se a lista já tiver dado se cria outro elemento e aponta o ant para o dado 2 e prox do dado 2 para o 1.
	}else{
		Elemento *atual; //criar novo elemento caso tenha dado no inicio da lista.
		atual = fim;
		novo->anterior = atual;
		atual->proximo = novo;
		fim = novo;
	}
	tamanho++;
}

//Inserir no inicio da lista:
void inserePosicao(int valor, int posicao) {
	posicao = posicao-1;
	Elemento *novo = aloca(valor);   //criar novo elemento
	//verificar se o inicio for nulo, se sim, inicio recebe novo e o fim vai ser novo também, pois se os dois são nulos o inico e fim recebe o novo.
	if(inicio==NULL){
		inicio=novo;
		fim=novo;
	//Se a lista já tiver dado se cria outro elemento e aponta o ant para o dado 2 e prox do dado 2 para o 1.
	}else{
		Elemento *atual; //criar novo elemento caso tenha dado no inicio da lista.
		Elemento *tmp;
		int i;

		// Decidindo o ponto de incio
		if (posicao < (tamanho/2)) {
			atual = inicio;
			i = 0;
		} else {
			atual = fim;
			i = tamanho;
		}

		// Percorrer para encontrar a posição
		while ((i != posicao) && (i >= 0) && (i <= tamanho)) {
			if (i < posicao) {
				i++;
				atual = atual->proximo;
			} else if (i > posicao) {
				i--;
				atual = atual->anterior;
			}

			if (posicao == i) {
				// novo->anterior = 
				// novo->proximo =
				// atual = novo;
				printf("Valor antecessor ao quero inserir %d\n", atual->anterior->valor);
				printf("Valor proximo ao quero inserir %d\n", atual->proximo->valor);
			}
		}



	}
	// tamanho++;
}

void mergeLista (Elemento *elementos, long int p, long int q, long int r){
	long int n1,n2,i,j,k;
	
	n1 = q-p+1;
	n2 = r-q;
	/*while(elementos){
		printf("*%d\n",elementos->valor);
		elementos = elementos->proximo;
	}*/
	//printf("n1: %d, n2: %d, p: %ld, q: %ld, r: %ld\n", n1, n2, p, q, r);
	Elemento *listaEsq ,*listaDir;
	
	//listaEsq = malloc(sizeof(Elemento)*(n1+1));
	//listaDir = malloc(sizeof(Elemento)*(n2+1));
	
	for(i=0;i<=n1-1;i++){
		listaEsq[i] = elementos[p+i];
		printf(">>esq[%d] = %d\n", i, listaEsq[i].valor);
	}
	
	for(j=0;j<=n2-1;j++){
		listaDir[j] = elementos[q+1+j];
		printf(">>dir[%d] = %d\n", j, listaDir[j].valor);
	}
		
	/*listaEsq[n1].valor = INT_MAX;
	listaDir[n2].valor = INT_MAX;*/

	i=j=0;
	for(k=p;k<=r;k++){
		if(listaEsq[i].valor <= listaDir[j].valor){
			elementos[k]=listaEsq[i];
			i=i+1;
		}
		else{
			elementos[k] = listaDir[j];
			
			j=j+1;
		}
	}
}

int merge2(int v[n], int ini, int meio, int fim, int aux[n]){
	int i=ini,j=meio+1,k=0,cont=0; 
	while(i<=meio && j<=fim){
		if(v[i] <= v[j]){
			aux[k++] = v[i++];
			cont++;
		}else{
			aux[k++] = v[j++];
			cont++;
		}
	}
	while(i<=meio)
	aux[k++] = v[i++];
	while(j<=fim)
	aux[k++] = v[j++];
	for(i=ini, k=0 ; i<= fim; i++, k++) 
	v[i]=aux[k];
	return cont;
}

int mergeSort2(int v[],int ini, int fim, int aux[]){
	int meio = (fim+ini)/2;
	int cont;
	if(ini < fim){
		mergeSort2(v,ini,meio,aux);
		mergeSort2(v,meio+1,fim,aux);
		cont=merge2(v,ini,meio,fim,aux);
	}
	return cont;
}

void mergeSortLista (Elemento *elementos, long int p, long int r){ 
	long int q = 0;
	//Elemento *aux = (Elemento*)malloc(sizeof(Elemento));
	/*while(elementos){
		printf("*%d\n",elementos->valor);
		elementos = elementos->proximo;
	}*/

	printf("%ld %ld\n", p, r);
	if(p<r){
		q = (p+r)/2;
		printf("entrou q=%d\n", q);
		mergeSortLista(elementos,p,q);
		mergeSortLista(elementos,q+1,r);
		mergeLista(elementos,p,q,r);
	}
}

/*void imprime(lista *l){
    no *nodo=l->head;
    int i;
    printf("\n\n");
    for(i=0;i<l->Nnos;i++){
        printf("\t[%d]",nodo->info);
        nodo=nodo->next;
    }
    /*printf("\n\n");
    nodo=l->head;
    for(i=0;i<l->Nnos;i++){
        printf("\t[%d]",nodo->id);
        nodo=nodo->next;
    }*/
    //printf("\n\n");
//}*

//Função para imprimir a lista:
void imprimeListaD() {
	int v[n];
	int aux[n];
	Elemento *atual;
	atual = inicio;
	
	gettimeofday(&begin, NULL);
	//mergeSortLista(atual, 0, tamanho-1);
	mergeSort2(v,0,tamanho - 1,aux);
    gettimeofday(&end, NULL);
    
    printf("Tempo de processamento da lista duplamente encadeada: %ld microsegundos\n\n", ((end.tv_sec - begin.tv_sec)*1000000L+end.tv_usec) - begin.tv_usec);
}

void imprimeListaE() {
	Elemento *atual;
	atual = inicio;
	while(atual){
		printf("%d\n",atual->valor);
		atual=atual->proximo;
	}
}
