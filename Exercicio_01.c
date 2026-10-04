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

Lista *lst_fim(Lista *lista, int valor){
    if(lista == NULL){
        return lst_insere(lista, valor);
    }

    Lista *aux;
    aux = lista;
    while(aux -> prox != NULL){
        aux = aux -> prox;
    }

    Lista *novo =  (Lista*) malloc(sizeof(Lista));
    
    novo -> info = valor;
    novo -> prox = NULL;
    aux -> prox = novo;
    
    return lista;
}

Lista *lst_insere_ordem (Lista *lista, int valor){

    if(lista == NULL || valor < lista -> info){
        return lst_insere(lista, valor);
    }
    Lista *anterior;
    Lista *atual;

    anterior = NULL;
    atual = lista;

    while(atual != NULL && valor > atual->info){
        anterior = atual;
        atual = atual->prox;
    }

    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo -> info = valor;
    novo -> prox = atual;
    anterior -> prox = novo;

    return lista;

}

int main (){

    Lista *minhalista = criarlista();

    minhalista = lst_insere(minhalista, 20);
    minhalista = lst_insere(minhalista, 10);
    minhalista = lst_insere(minhalista, 5);
    minhalista = lst_fim(minhalista, 30);
    minhalista = lst_insere_ordem(minhalista, 15);
    
    
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

    while(aux != NULL ){
        printf("%d\n", aux ->info);
        aux = aux ->prox;
    }
}
