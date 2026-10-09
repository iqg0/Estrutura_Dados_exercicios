#include<stdio.h>
#include<stdlib.h>
#include "FilaDinamica.h"

struct fila{
    struct elemento *inicio;
    struct elemento *final;
};

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Fila* cria_Fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    if(fi !=  NULL){
        Elem* no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int tamanho_Fila(Fila* fi){
    if(fi == NULL) return 0;
    int cont = 0;
    Elem*  no = fi->inicio;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int Fila_cheia(Fila* fi){
    return 0;
}

int main(){
    Fila *fi; // Ponteiro para o descritor
    int x = cria_Fila();
    libera_Fila(fi);
    int x = tamanho_Fila(fi);
    int x = Fila_cheia(fi); // Ou if(Fila_cheia(fi));
}