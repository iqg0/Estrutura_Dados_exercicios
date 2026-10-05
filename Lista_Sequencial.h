#define MAX 100

struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;

};

typedef struct lista Lista;

// Cria uma lista vazia
Lista* cria_lista(); 

// Libera a lista
void libera_lista(Lista* li);

// Verifica o tamanho da lista
int tamanho_lista(Lista* li);

// Verifica se a lista esta cheia
int lista_cheia(Lista* li);

// Verifica se a lista esta fazia
int lista_vazia(Lista* li);

// Insere no final da lista
int insere_lista_final(Lista* li, struct aluno al);

// Insere no inicio da lista
int insere_lista_inicio(Lista* li, struct aluno al);

// Insere de forma ordenada na lista
int insere_lista_ordenada(Lista* li, struct aluno al);

// Remove do final da lista 
int remove_lista_final(Lista* li);

// Remove do incio da lista
int remove_lista_inicio(Lista* li);

// Remover um elemento qualquer
int remove_lista(Lista* li, int mat);