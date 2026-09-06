#include <stdio.h>

int main(){

    int ano = 0;

    scanf("%d", &ano);

    if((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0){
        printf("Ano Bissexto\n");
    }
    else{
        printf("Ano Não-bissexto\n");
    }

    return 0;
}