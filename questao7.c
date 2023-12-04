#include <stdio.h>

int main() {

    char nome[50], sexo;
    float altura, peso;
    int numHomens = 0, numMulheres = 0;
    float alturaHomens = 0, alturaMulheres = 0, alturaTotal = 0;
    float pesoHomens = 0, pesoMulheres = 0, pesoTotal = 0;

    for (int i = 0; i < 10; i++) {

        printf("digite o nome da pessoa %d: ", i + 1);
        scanf("%49s", nome);

        printf("digite o sexo (m/f) da pessoa %d: ", i + 1);
        scanf(" %c", &sexo);

        /*verificando sexo*/
        if (!(sexo == 'm' || sexo == 'f')) {
            printf("opção inválida para sexo. tente novamente.\n");
            i--; 
            continue;
        }

        printf("digite a altura (em metros) da pessoa %d: ", i + 1);
        scanf("%f", &altura);

        printf("digite o peso (em kg) da pessoa %d: ", i + 1);
        scanf("%f", &peso);

        if (sexo == 'm') {
            numHomens++;
            alturaHomens += altura;
            pesoHomens += peso;
        } else if (sexo == 'f') {
            numMulheres++;
            alturaMulheres += altura;
            pesoMulheres += peso;
        }

        alturaTotal += altura;
        pesoTotal += peso;
    }

    /*calculando médias*/
    float mediaAlturaHomens = numHomens > 0 ? alturaHomens / numHomens : 0;
    float mediaAlturaMulheres = numMulheres > 0 ? alturaMulheres / numMulheres : 0;
    float mediaAlturaTotal = numHomens + numMulheres > 0 ? alturaTotal / (numHomens + numMulheres) : 0;
    float mediaPesoHomens = numHomens > 0 ? pesoHomens / numHomens : 0;
    float mediaPesoMulheres = numMulheres > 0 ? pesoMulheres / numMulheres : 0;
    float mediaPesoTotal = numHomens + numMulheres > 0 ? pesoTotal / (numHomens + numMulheres) : 0;

    printf("\nresultados:\n");
    printf("número de homens: %d\n", numHomens);
    printf("número de mulheres: %d\n", numMulheres);
    printf("altura média dos homens: %.2f metros\n", mediaAlturaHomens);
    printf("altura média das mulheres: %.2f metros\n", mediaAlturaMulheres);
    printf("altura média do grupo: %.2f metros\n", mediaAlturaTotal);
    printf("peso médio dos homens: %.2f kg\n", mediaPesoHomens);
    printf("peso médio das mulheres: %.2f kg\n", mediaPesoMulheres);
    printf("peso médio do grupo: %.2f kg\n", mediaPesoTotal);

    return 0;
}
