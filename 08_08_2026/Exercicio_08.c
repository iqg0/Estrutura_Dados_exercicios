#include <stdio.h>

int main () {

    int N = 0;
    int termo1 = 1;
    int termo2 = 1;

    scanf("%d", &N);

    if(N == 1 || N == 2){
        printf("Termo = 1\n");
        
    }else{
        for(int count = 0; count < N-2; count++){

                int NovoTermo = termo2 + termo1;
                termo2 = termo1;
                termo1 = NovoTermo;
        }
        printf("Termo = %d\n", termo1);
        
        }
    }




