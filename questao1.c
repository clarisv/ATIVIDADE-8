/*Elabore um algoritmo que, lendo estes dados, calcule e imprima:

a quantidade de respostas ótimo;
a diferença percentual entre respostas bom e regular;
a média de idade das pessoas que responderam ruim;
a percentagem de respostas péssimo e a maior idade que utilizou esta opção;
a diferença de idade entre a maior idade que respondeu ótimo e a maior idade que respondeu ruim. */


#include <stdio.h>

int main() {

    int idade, opniao;
    int opinioes_Otimo = 0;
    int opinioes_Bom = 0;
    int opinioes_Regular = 0;
    int opinioes_Ruim = 0;
    int opinioes_Pessimo = 0;
    int soma_idade_Ruim = 0;
    float media_Idade_Ruim = 0.0;
    float diferenca_percentual = 0.0;
    int idade_Maior_Pessimo = 0;
    int idade_Maior_Otimo = 0;
    float percentagem_Pessimo = 0.0;
    int quantidade = 0;
    char continuar;

    do {
        printf("\ndigite sua idade: ");
        scanf("%d", &idade);

        printf("\nopcoes validas: \n");
        printf("1 - otimo\n");
        printf("2 - bom\n");
        printf("3 - regular\n");
        printf("4 - ruim\n");
        printf("5 - pessimo\n");

        printf("\nqual a sua opniao sobre o filme?: ");
        scanf("%d", &opniao);

        quantidade++;

        switch(opniao){
            case 1:
                printf("otimo\n");
                opinioes_Otimo++;
                idade_Maior_Otimo = idade > idade_Maior_Otimo ? idade : idade_Maior_Otimo;
                break;
            case 2:
                printf("bom\n");
                opinioes_Bom++;
                break;
            case 3:
                printf("regular\n");
                opinioes_Regular++;
                break;
            case 4:
                printf("ruim\n");
                opinioes_Ruim++;
                soma_idade_Ruim += idade;
                break;
            case 5:
                printf("pessimo\n");
                opinioes_Pessimo++;
                idade_Maior_Pessimo = idade > idade_Maior_Pessimo ? idade : idade_Maior_Pessimo;
                break;
            default:
                printf("opcao invalida!\n");
                break;
        }

    printf("\ndeseja continuar (s/n)? ");
    scanf("%c", &continuar);

    }while(continuar == 's' || continuar == 'S');

    diferenca_percentual = (float)(opinioes_Bom - opinioes_Regular) / quantidade * 100;
    media_Idade_Ruim = opinioes_Ruim > 0 ? (float)soma_idade_Ruim / opinioes_Ruim : 0;
    percentagem_Pessimo = opinioes_Pessimo / (float)quantidade * 100;

    printf("\nquantidade de respostas otimo: %d\n", opinioes_Otimo);
    printf("diferenca percentual entre respostas bom e regular: %.2f%%\n", diferenca_percentual);
    printf("media de idade das pessoas que responderam Ruim: %.2f\n", media_Idade_Ruim);
    printf("percentagem de respostas Pessimo: %.2f%%, Maior idade que utilizou esta opcao: %d\n", percentagem_Pessimo, idade_Maior_Pessimo);
    printf("diferenca de idade entre a maior idade que respondeu otimo e a maior idade que respondeu ruim: %d\n", idade_Maior_Otimo - idade_Maior_Pessimo);

    return 0;
}
