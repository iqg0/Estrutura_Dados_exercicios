#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));
    
    int guess = 0;
    int min = 50;
    int max = 100;
    int random_number = (rand() % (max -min +1)) + min; // Formula para gerar um numero aleatorio(pseudo random num)
    int tentativas = 0;

    do {

        printf("Digite um numero: ");
    scanf("%d", &guess);
    int diferenca = abs(guess - random_number);

    if (guess < random_number){
        printf("Muito pequeno!\n");

            if(diferenca <= 3){
                printf("Muito perto!\n");
            }else if(diferenca <=5){
                printf("Perto\n");
            }
            else{
                printf("Longe\n");
            }
    }
    if(guess > random_number){
        printf("Muito grande!\n");

         if(diferenca <= 3){
                printf("Muito perto!\n");

            }else if(diferenca <=5){
                printf("Perto!\n");
            }
            else{
                printf("Longe\n");
            }
    }
    tentativas = tentativas + 1;
    }while(guess != random_number);
    
    
    printf("Correto! tentativas = %d, o numero era %d\n", tentativas, random_number);


    return 0;
}