/*Faça um algoritmo que leia um número positivo e imprima seus divisores. 
Exemplo: Os divisores do número 66 são: 1, 2, 3, 6, 11, 22, 33 e 66.*/

#include <stdio.h>

int main() {

    int num;
    int count = 0;

    printf("\ndigite um numero positivo: ");
    scanf("%d", &num);

    if (num <= 0) {
        printf("opcao invalida. por favor, insira um numero positivo.\n");
        return 1;  
    }

    printf("os divisores do numero %d sao: ", num);

    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            printf("%d", i);

            if (i != num) {
                printf(", ");
            }

            count++;
        }
    }

    return 0;
}
