#include <stdio.h>
#include<stdlib.h>


typedef struct lista {
int info;
struct lista* prox;
} Lista ;

Lista *criarlista(void){
    return NULL;
}

int main (){

    Lista *minhalista = criarlista();

    if(minhalista == NULL){
        printf("Lista vazia!");
    }
    else{
        ("A lista nao esta vazia");
    }

    return 0;
}