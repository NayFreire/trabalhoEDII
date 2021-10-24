#include<stdio.h>
#include<stdlib.h>

#include "ListaEncadeada.h"

/* int counter = 0;
void numComparacoes(){
    counter++;
} */

void mergeLista (Elemento *elementos, long int p, long int q, long int r){
	long int n1,n2,i,j,k;
	
	n1 = q-p+1;
	n2 = r-q;
	
	Elemento *listaEsq ,*listaDir;
	
	listaEsq = (Elemento*) malloc(sizeof(Elemento)*(n1+1));
	listaDir = (Elemento*) malloc(sizeof(Elemento)*(n2+1));
	
	for(i=0;i<=n1-1;i++){
		listaEsq[i] = elementos[p+i];
	}
	
	for(j=0;j<=n2-1;j++){
		listaDir[j] = elementos[q+1+j];
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

void mergeSortLista (Elemento *elementos, long int p, long int r){ 
	long int q = 0;
	if(p<r){
		q = (p+r)/2;
		mergeSortLista(elementos,p,q);
		mergeSortLista(elementos,q+1,r);
		mergeLista(elementos,p,q,r);
	}
}