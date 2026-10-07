#include<stdio.h>
#include<stdlib.h>
#include "FilaEstatica.h"

struct fila {
    int inicio, final, qtd;
    struct aluno dados[MAX];
};

Fila* cria_Fila(){
    Fila *fi = (Fila*) malloc(sizeof(struct fila));
    if(fi != NULL) {
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0; 
    }
    return fi;     
}

void libera_Fila(Fila* fi){
    free(fi);
}

int tamanho_Fila(Fila* fi){
    if(fi == NULL) return -1;
    return fi-> qtd;
}

int Fila_cheia(Fila* fi){
    if(fi == NULL) return -1; 
    if(fi->qtd == MAX) 
        return 1;
    else 
    return 0;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return -1;
    if(fi->qtd == 0)
        return 1;
    else
        return 0;
}

int insere_Fila(Fila* fi, struct aluno al){
    if(fi == NULL) return 0;
    if(Fila_cheia(fi)) return 0;
    fi->dados[fi->final] = al;
    fi->final = (fi->final+1) %MAX;
    return 1;
}

int main(){
    Fila *fi;

      struct aluno dados_aluno;
    dados_aluno.matricula = 1;
    strcpy(dados_aluno.nome, "Maria");
    dados_aluno.n1 = 7.5;
    dados_aluno.n2 = 8.0;
    dados_aluno.n3 = 9.0;

    fi = cria_Fila();
    libera_Fila(fi);
    int x = Fila_cheia(fi); // Ou if(Fila_cheia(fi));
    int x = Fila_vazia(fi); // OU if(Fila_vazia(fi));
    int x = insere_Fila(fi, dados_aluno);
}