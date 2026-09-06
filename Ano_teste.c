


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

    typedef struct {
        int dia;
        int mes;
        int ano;
    } Data ;

    bool validaData(int , int mes, int ano){

        if(mes <= 0 || mes > 12){
            return false;
        }
        if(dia <= 0 || dia > 31){
            return false;
        }

        int maxDias = 0;

        switch (mes){
            case 4: 
            case 6:
            case 9:
            case 11:

            maxDias = 30;
            break;

            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:

            maxDias =31;
            break;

            case 2:
                if((ano % 4 == 0) && (ano % 100 != 0 || ano % 400 == 0)){
                    maxDias =29;
                }
                else {
                    maxDias = 28;
                }
                break;

            default:
                break;
        }

        if(dia <= maxDias){
            return true;
        }
        else{
            return false;
        }



    }

    bool preencherData(int dia, int mes, int ano, Data *d){

        if(validaData(dia, mes, ano)){
                d -> dia = dia;
                d -> mes = mes;
                d -> ano = ano;
            return true;
        }
        else{
            return false;
        }


    }

    int bissextosAte(int ano) {
        return (ano/4) - (ano/100) + (ano/400);
    }

    bool ehBissexto(int ano){
        return (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
    }

    long converteDias(int dia, int mes, int ano){

        long diasAnos = (long) (ano - 1) * 365 + bissextosAte(ano -1);

        int diasPorMes[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        long diasMeses = 0;
        for (int i = 0; i < mes - 1; i++) {
            diasMeses += diasPorMes[i];
        }
        if (mes > 2 && (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0))) {
            diasMeses += 1;
        }
        return diasAnos + diasMeses + dia;

    }

    long diferencaDias(Data d1, Data d2) {
        long total1 = converteDias(d1.dia, d1.mes, d1.ano);
        long total2 = converteDias(d2.dia, d2.mes, d2.ano);
        return labs(total1 - total2); // labs = valor absoluto para long, está em <stdlib.h>
    }

    void escreverExtenso(Data d){
        char *nomesMeses[] = {"janeiro","fevereiro","marco","abril","maio","junho","julho","agosto","setembro","outubro","novembro","dezembro"};
        printf("%d de %s de %d\n", d.dia, nomesMeses[d.mes - 1], d.ano);
    }

    Data somaDias(Data d, int n){
        long totalDias = converteDias(d.dia, d.mes, d.ano) + n;

        int ano = 1;
        while(true){
            int diasNoAno = ehBissexto(ano) ? 366 : 365;
            if(totalDias > diasNoAno){
                totalDias -= diasNoAno;
                ano++;
            }
            else{
                break;
            }
        }

        int diasPorMes[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if(ehBissexto(ano)){
            diasPorMes[1] = 29;
        }

        int mes = 1;
        while(totalDias > diasPorMes[mes - 1]){
            totalDias -= diasPorMes[mes - 1];
            mes++;
        }

        Data resultado;
        resultado.dia = (int) totalDias;
        resultado.mes = mes;
        resultado.ano = ano;
        return resultado;
    }

int main () {

    int dias = 0;
    int meses = 0;
    int anos = 0;
    int dias2 = 0;
    int meses2 = 0;
    int anos2 = 0;

    printf("Informe o dia: \n");
    scanf("%d", &dias);

    printf("Informe o mes: \n");
    scanf("%d", &meses);

    printf("Informe o ano: \n");
    scanf("%d", &anos);

    
    printf("Informe o dia2: \n");
    scanf("%d", &dias2);

    printf("Informe o mes2: \n");
    scanf("%d", &meses2);

    printf("Informe o ano2: \n");
    scanf("%d", &anos2);

    Data data2;
    Data minhasdatas;

    bool sucesso = preencherData(dias, meses, anos, &minhasdatas);
    bool sucesso2 = preencherData(dias2, meses2, anos2, &data2);

    if(sucesso && sucesso2){

        printf("Data validada!\n");

        printf("Dia: %d\n", minhasdatas.dia); 
        
        printf("Mes: %d\n", minhasdatas.mes); 
        
        printf("Ano: %d\n", minhasdatas.ano); 

        long diferenca = diferencaDias(minhasdatas, data2);
        printf("Diferenca: %ld dias\n", diferenca);

        printf("Data por extenso: ");
        escreverExtenso(minhasdatas);

        int qtdDias = 0;
        printf("Informe a quantidade de dias a somar a primeira data: \n");
        scanf("%d", &qtdDias);

        Data novaData = somaDias(minhasdatas, qtdDias);
        printf("Nova data: %d/%d/%d\n", novaData.dia, novaData.mes, novaData.ano);
        printf("Nova data por extenso: ");
        escreverExtenso(novaData);
    }
    else{
        printf("Nao foi possivel validar essa data!");
    }
    return 0;
}