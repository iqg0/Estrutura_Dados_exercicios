#include<stdio.h>
#include<stdlib.h>
#include "FilaEstatica.h"

struct fila {
    int inicio, final, qtd;
    struct aluno dados[MAX];
};

Fila* cria_fila(){
    Fila *fi = (Fila*) malloc(sizeof(struct fila));
    if(fi != NULL) {
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0; 
    }
    return fi;     
}

void libera_fila(Fila* fi){
    free(fi);
}

int main(){
    Fila *fi;
    fi = cria_fila();
    libera_fila(fi);
}