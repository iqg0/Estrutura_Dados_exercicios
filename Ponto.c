#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Ponto.h" // Inclui os prototipos


// Definicao dos tipos de dados
struct ponto {
    float x;
    float y;
};

Ponto* pto_cria(float x, float y){
     Ponto* p = (Ponto*) malloc(sizeof(Ponto)); // Aloca um espaco na memoria para guardar x e y


// Se p nao for igual a NULL atribui os valores de x e y
// a eles mesmos acessando o conteudo do ponteiro p
     if(p != NULL){
        p-> x = x;
        p-> y = y;
     }
     
// Retorna os valores x e y contidos em p
     return p;
}

void pto_libera(Ponto * p){
// Libera o pontp p (o espaco de memoria alocado com malloc para o p)
    free(p);
}

// Recupera por referencia o valor de um ponto
void pto_acessa (Ponto* p, float* x, float* y){ // Acessa o conteudo de p e devolve para os dois ponteiros *x e *y
    *x = p->x;
    *y = p->y;

    // Devolvendo dois valores por referencia ja que por return apenas 1 seria possivel
}

// Atribui a um ponto as coordenadas "x" e "y"
void pto_atribui(Ponto* p, float x, float y){ // passa os valores de volta para o ponteiro de p
    p-> x = x;
    p-> y = y;
}

// Calcula a distancia entre dois pontos
float pto_distancia(Ponto* p1, Ponto* p2){
    float dx = p1-> x - p2-> y; // diferenca do termo x de um ponto (dx = diferenca de dois x)
    float dy = p1-> y - p2-> x; // difenca do termo y de um ponto (dy = diferenca de dois y)
    return sqrt(dx * dx + dy * dy); // (retorna a raiz de dx ao quadrado + raiz de dy ao quadrado)
}

int main(){
    float d;
    Ponto* p, *q;
    //Ponto r; //ERRO (Nao sera mais possivel declarar uma variavel para a estrutura, apenas ponteiros)
    p = pto_cria(10,11);
    q = pto_cria(7,25);
    // q-> x = 2; //ERRO
    d = pto_distancia(p,q);
    printf("Distancia entre os pontos: %f\n", d);
    pto_libera(q);
    pto_libera(p);

    system("pause");
    return 0;
}