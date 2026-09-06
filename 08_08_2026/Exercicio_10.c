#include <stdio.h>

int main () {

    double n1 = 0.0, n2 = 0.0;
    double resultado = 0.0;
    char operador = '\0';
    char saida = '\0';

    
    printf("Digite # para sair / Digite 0 para continuar\n");
    scanf(" %c", &operador);


    while(operador != '#') {

    printf("Informe um numero: ");
    scanf("%lf", &n1);

    printf("Informe o operador (*, /, +, -): ");
    scanf(" %c", &operador);

    printf("Informe outro numero: \n");
    scanf("%lf", &n2);

    switch(operador) {

        case '*': resultado = n1 * n2;
            printf("%.2lf * %.2lf = %.2lf\n", n1, n2, resultado);
            break;

        case '/': 
            if(n2 == 0){
                printf("Informe um numero valido(nao e possivel realizar divisao por zero!)\n");
                break;
            }
            resultado = n1 / n2;
           printf("%.2lf / %.2lf = %.2lf\n", n1, n2, resultado);
            break;



        case '+': resultado = n1 + n2;
            printf("%.2f + %.2f = %.2f\n", n1, n2, resultado);
            break;


        
        case '-': resultado = n1 - n2;
            printf("%.2f * %.2f = %.2f\n", n1, n2, resultado);
            break;


        default: 
            printf("Operador invalido!\n");
    }

        printf("Digite # para sair / Digite 0 para continuar\n");
        scanf(" %c", &operador);

        }

    


    return 0;
}