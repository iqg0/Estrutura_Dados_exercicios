#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista_Sequencial.h"

struct lista {
    int qtd;
    struct aluno dados[MAX]; // Vetor de tamanho MAX da estrutura aluno (ate 100 alunos)
};

Lista* cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista)); // variavel que guarda um espaco de memoria para o struct liista
    if(li != NULL) // Verifica se a criacao da lista foi bem sucedida
        li-> qtd = 0; // Digo que minha lista tem 0 posicoes ocupadas

    return li;
}
void libera_lista(Lista* li){
    free(li); // libera a memoria que foi alocada para o struct lista
}

int tamanho_lista(Lista* li){
    if(li == NULL) // Se a lista estiver fazia retorna um numero negativo significando um erro
        return -1;
    else 
        return li-> qtd; // Se a lista tiver algum elemento retorna a quantidade
}

int lista_cheia(Lista* li){
    if(li == NULL)
        return -1;
    return (li->qtd == MAX); //retorna qtd se o valor da fila for igual a MAX (se ela estiver totalmente cheia)
    // Se for verdade retorna 1 se falso retornara 0   
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return -1;
    return (li-> qtd == 0); // Aqui se compara com 0 se a lista igual a zero entao esse sera o valor retornada(o valor da lista)
    // Se verdadeiro retorna 1 se falso 0
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0; 
    if(lista_cheia(li))
        return 0;
    li-> dados[li->qtd] = al; // a posicao apontada por qtd recebe os dados de al
    li-> qtd++;
    return 1; // retorna 1 caso a insercao de certo
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL) //verifica se a lista e valida
        return 0;
    if(lista_cheia(li)) // verifica se a lista esta cheia
        return 0;
    int i;
    for(i = li-> qtd-1; i>=0; i--){ //qtd-1 = ultimo elemento que eu inseri na lista
        li-> dados[i+1] = li->dados[i]; // dados[i+1] = a posicao da frente recebe os dados que estao quardados na posicao i (i = a posicao anterior )
    li->dados[0] = al; // dados[0] = dados na posicao 0 (comeco da lista) recebe um novo dado/elemento = al
    li->qtd++; // incrementa a quantidade de elementos
    return 1;
    }
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL); // verificar se lista e vaga
        return 0;
    if(lista_cheia(li)); // verificar se a lista e cheia
        return 0;
    int k,i = 0;
    // enquanto for menor que a quantidade de elementos da minha lista que estou percorrendo
    // sera inserido de forma ordenada pela matricula do aluno que esta sendo inserido 
    // se a matricula que esta na lista for menor que a matricula que esta sendo inserida do novo aluno(significa que ele e maior)
    // ele ira andando na lista ate chegar na possicao onde ele deve estar
    while(i<li->qtd && li->dados[i].matricula < al.matricula)
        i++;

    for(k=li->qtd-1; k>= i; k--) // doslocamento da posicao de todos qtd-1 ate a posicao i
        li->dados[k+1] = li->dados[k];
    li->dados[i] = al; // insere na posicao i o meu dado(dados da posicao i recebe os dados do aluno)
    li-> qtd++; // incrementa a quantidade
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL);
        return 0;
    if(li-> qtd == 0) // se qtd == 0 a lista e vazia nao tem o que remover
    li->qtd--; // diminui a quantidade de elementos da lista
    return 1;
        return 0;
}

int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if(li-> qtd == 0)
        return 0;
    int k,i = 0;
    while(i< li->qtd && li-> dados[i].matricula != mat)
        i++;
    if(i == li-> qtd) // Elemento nao encontrado
        return 0;

    for (k = i; k <  li-> qtd-1; k++)
        li-> dados[k] = li-> dados [k+1];
    li-> qtd--;
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if(li-> qtd == 0)
        return 0;
    int k = 0;

    // Deslocamento da lista
    // Apartir da posicao 0 ate quantidade -1
    for(k = 0; k < li->qtd-1; k++)
    // Posicao k recebe posicao k+1
        li-> dados[k] = li-> dados[k+1];
    li-> qtd--; // Decrementa do final
    return 1;
}

int remove_lista(Lista* li, int mat){
    if(li == NULL) return 0;
    if(li-> qtd == 0) return 0;
    int k,i = 0;

    // Enquanto i for menor que a quantidade de elementos &&
    // A matricula da posicao i do aluno for diferente da matricula fornecida
    while(i < li->qtd && li-> dados[i].matricula != mat);
    // anda a lista
        i++;

    // se a posicao i for igual a quantida
    // segnifica que nunca foi achada a condicao anterior(o aluno com a matriculaa que estava sendo procurada)
    if(i == li-> qtd) return 0; // Elemento nao encontrado

    // Caso ache o que tiver na frente dele e deslocado uma posicao para atras
    for(k = i; k< li->qtd-1; k++);
    // k recebe o valor de k+1
        li->dados[k] = li->dados[k+1];
    // diminui a quanotidade de elementos da lista
    li->qtd--;
    return 1;
}

int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    // Verificar se a lista existe, se a posicao e positiva (1, 2, 3...) e se a posicao for maior que a quantidade
    if(li == NULL || pos <= 0 || pos > li->qtd)
        return 0;
    // Se passou no teste pego a informacao da posicao - 1 dos dados
    // Pego o conteudo dessa posicao e copio para o ponteiro al (o ponteiro para estrutura)
    // E modificado o conteudo do ponteiro al (o ponteiro para estrutura com os dados que esta na posicao pos-1)
    *al = li->  dados[pos-1];
    return 1;
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL)
        return 0;
    int k,i = 0;
    // De 0 ate o ultimo elemento da lista equanto o valor i na posicao da matricula for diferente da matricula informada
    while(i<li->qtd && li->dados[i].matricula != mat)
        i++;
    // Se i for igual a quantidade entao nao foi possivel encontrar o elemento procurado
    if(i == li->qtd) // Elemento nao foi encontrado
        return 0;
    // Se o elemento for encontrado pego os dados da posicao i e guardop dentro do ponteiro al (dentro do conteudo do struct aluno)
    *al = li-> dados[i];
    return 1;
}

int main () {
    Lista *li; // Ponteiro pro tipo lista 
    li = cria_lista();
    libera_lista(li);
    int x = tamanho_lista(li);
    int x = lista_cheia(li);
    int x = lista_vazia(li);
    if (lista_vazia(li));

    struct aluno dados_aluno;
    dados_aluno.matricula = 1;
    strcpy(dados_aluno.nome, "Maria");
    dados_aluno.n1 = 7.5;
    dados_aluno.n2 = 8.0;
    dados_aluno.n3 = 9.0;

    struct aluno matricula_aluno;
    matricula_aluno.matricula = 1;


    int x = insere_lista_final(li, dados_aluno);
    int x = insere_lista_inicio(li, dados_aluno);
    int x = insere_lista_ordenada(li, dados_aluno);
    int x = remove_lista_final(li);
    int x = remove_lista_inicio(li);
    int x = remove_lista(li, matricula_aluno.matricula);
    int x = consulta_lista_pos(li, posicao, &dados_aluno);
    int x = consulta_lista_mat(li, posicao, &dados_aluno);
}