#include <stdio.h>
#include<stdlib.h>


typedef struct lista {
    int info;
    struct lista* prox;
} Lista ;

Lista *criarlista(void){
    return NULL;
}

Lista *lst_insere(Lista *lista, int valor){
    Lista *novo = (Lista*) malloc(sizeof(Lista)); 
    
    novo ->info = valor;
    novo -> prox = lista;

    return novo;
}

void imprimirLista(Lista *lista);
void lst_fim(lista, valor);


int main (){

    Lista *minhalista = criarlista();

    minhalista = lst_insere(minhalista, 20);
    minhalista = lst_insere(minhalista, 10);
    minhalista = lst_insere(minhalista, 5);
    
    
    if(minhalista == NULL){
        printf("Lista vazia!");
    }
    else{
        printf("A lista nao esta vazia\n");
    }

    imprimirLista(minhalista);

    return 0;
}

void imprimirLista(Lista *lista){
    Lista *aux;
    aux = lista;

    while(aux != NULL){
        printf("%d\n", aux ->info);
        aux = aux ->prox;
    }
}