/*Construa um algoritmo que calcule e imprima:

qual o período mais usado de todos e a que elevador pertence;
 qual é o elevador mais frequentado e em que período se concentra o maior fluxo;
qual a diferença percentual entre o mais usado dos horários e o menos usado;
qual a percentagem sobre o total de serviços prestados do elevador de média utilização. */


#include <stdio.h>

int main() {
    int i;
    int elevadorAM = 0, elevadorAV = 0, elevadorAN = 0;
    int elevadorBM = 0, elevadorBV = 0, elevadorBN = 0;
    int elevadorCM = 0, elevadorCV = 0, elevadorCN = 0;
    int total_usos = 0;
    int max_usos = 0;
    char mais_usado_elevador, mais_usado_periodo, elevador, periodo;

    /*loop para coletar dados*/
    for (i = 0; i < 50; i++) {
        printf("\ninforme o elevador mais utilizado pelo morador %d (A/B/C): ", i);
        scanf(" %c", &elevador);

        if (elevador != 'A' && elevador != 'B' && elevador != 'C') {
            printf("opcao invalida! Por favor, escolha A, B ou C.\n");
            i--;
            continue;
        }

        printf("informe o periodo que foi utilizado (M/V/N) pelo morador %d: ", i);
        scanf(" %c", &periodo);

        /*contar uso do elevador por periodo*/
        switch (elevador) {
            case 'A':
                elevadorAM++;
                break;
            case 'B':
                elevadorBM++;
                break;
            case 'C':
                elevadorCM++;
                break;
            default:
                printf("elevador invalido!\n");
                i--;
                continue;
        }

        switch (periodo) {
            case 'M':
                elevadorAM++;
                break;
            case 'V':
                elevadorAV++;
                break;
            case 'N':
                elevadorAN++;
                break;
            default:
                printf("entrada invalida!\n");
                i--;
                continue;
        }

        total_usos++;

        /*elevador mais usado*/
        if (elevadorAM >= elevadorAV && elevadorAM >= elevadorAN) {
            mais_usado_elevador = 'A';
            mais_usado_periodo = 'M';
        } else if (elevadorAV >= elevadorAM && elevadorAV >= elevadorAN) {
            mais_usado_elevador = 'B';
            mais_usado_periodo = 'V';
        } else if (elevadorAN >= elevadorAM && elevadorAN >= elevadorAV) {
            mais_usado_elevador = 'C';
            mais_usado_periodo = 'N';
        }

        char elevador_mais_frequentado;
        int total_elevador_mais_frequentado = 0;

        if (elevadorAM + elevadorAV + elevadorAN > total_elevador_mais_frequentado) {
            total_elevador_mais_frequentado = elevadorAM + elevadorAV + elevadorAN;
            elevador_mais_frequentado = 'A';
        }
        if (elevadorBM + elevadorBV + elevadorBN > total_elevador_mais_frequentado) {
            total_elevador_mais_frequentado = elevadorBM + elevadorBV + elevadorBN;
            elevador_mais_frequentado = 'B';
        }
        if (elevadorCM + elevadorCV + elevadorCN > total_elevador_mais_frequentado) {
            total_elevador_mais_frequentado = elevadorCM + elevadorCV + elevadorCN;
            elevador_mais_frequentado = 'C';
        }

        /*calculo percentual*/
        float percentual = ((float)total_elevador_mais_frequentado / total_usos) * 100;

        printf("\no elevador mais utilizado pelo morador %d foi o %c\n", i, elevador_mais_frequentado);
        printf("o periodo mais utilizado pelo morador %d foi o %c\n", i, mais_usado_periodo);
        printf("a diferenca percentual entre o mais usado e o menos usado foi de %.2f%%\n", percentual);
    }

    return 0;
}
