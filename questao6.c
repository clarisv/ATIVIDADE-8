/*Desenvolver um algoritmo que solicita o usuário um determinado um mês/ano, 
determinar e exibir o número de dias do mês/ano digitado. Considerar a existência de anos bissextos: (ano % 4 = 0 e ano % 100 =/= 0) ou ano % 400 = 0. Ao final do programa deve ser impressa a seguinte mensagem: VOCÊ DESEJA OUTRAS ENTRADAS (S/?)? Se a resposta for S o programa deverá retornar ao começo, 
caso contrário (qualquer outro caractere) deverá encerrar a sua execução. */


#include <stdio.h>

int main(){

    int mes, dias, ano;
    char resposta;

    do {

        printf("\ndigite o mes (1 a 12): ");
        scanf("%d", &mes);

        /*se for uma resposta nao existente*/
        if (mes < 1 || mes > 12) {
            printf("mes invalido. tente novamente.\n");
            continue;  
        }

        printf("digite o ano: ");
        scanf("%d", &ano);

        if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) {
            /*ano bissexto*/
            switch (mes) {
                case 2:
                    dias = 29;
                    break;
                case 4: case 6: case 9: case 11:
                    dias = 30;
                    break;
                default:
                    dias = 31;
                    break;
            }
        } else {
            /*ano nao bissexto*/
            switch (mes) {
                case 2:
                    dias = 28;
                    break;
                case 4: case 6: case 9: case 11:
                    dias = 30;
                    break;
                default:
                    dias = 31;
                    break;
            }
        }

        printf("o mes %d/%d tem %d dias.\n", mes, ano, dias);

        printf("deseja outras entradas (s/?)? ");
        scanf(" %c", &resposta);

    } while (resposta == 's');

    printf("programa encerrado.\n");

    return 0;
}



