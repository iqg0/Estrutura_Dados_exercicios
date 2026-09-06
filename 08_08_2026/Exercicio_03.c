#include <stdio.h>

int main(){

    int patos = 0;
    int coelhos = 0;
    int TotalCabecas = 0;
    int TotalPatas = 0;

    printf("Informe o total de cabecas: \n");
    scanf("%d",&TotalCabecas);
    printf("Informe o total de patas: \n");
    scanf("%d", &TotalPatas);

    coelhos = (TotalPatas/2) - TotalCabecas;
    patos = TotalCabecas - coelhos;

// Teste caso (Total de patas for um numero impar)
    if(TotalPatas % 2 != 0){
        printf("Numero de patas invalido!\n");
        return 0;
    }
// Teste caso numero menor de patas for menor que o numero de cabecas informadas pelo usuario
    if(TotalPatas < (TotalCabecas*2)){
        printf("Numero de patas invalido!\n");
        return 0;
    }
// Teste caso o numero de patas for maior que o numero de cabecas informadas pelo usuario
    if(TotalPatas > (TotalCabecas*4)){
        printf("numero de patas invalido");
        return 0;
    }
    else {
        printf("Total de patos: %d, total de coelhos: %d", patos, coelhos);
    }
        return 0;
}