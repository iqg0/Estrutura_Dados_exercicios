#include <stdio.h>

    void calcularReajuste(float preco, float *reajuste, float *novoPreco);

int main (){

        float preco = 0.0f;
        float reajuste = 0.0f;
        float novoPreco = 0.0f;

        do{
            
            printf("Informe o valor do produto: ");
            scanf("%f", &preco);

            if(preco < 0){
                printf("O programa foi encerrado!");
            }
            else{
                calcularReajuste(preco, &reajuste, &novoPreco);
                printf("reajuste = $%.2f, novo preco = $%.2f\n", reajuste, novoPreco);
            }
        }while(preco >= 0);   
        
    return 0;
}


    void calcularReajuste(float preco, float *reajuste, float *novoPreco){
        
        *reajuste = preco * 0.20;
        *novoPreco = *reajuste + preco;

    }