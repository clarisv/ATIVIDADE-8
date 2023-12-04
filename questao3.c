/*Escreva um programa que leia um número inteiro, maior ou igual a zero, do usuário. 
Imprima o enésimo termo da sequência de Fibonacci. Essa sequência começa no termo de ordem zero, e, a partir do segundo termo, seu valor é dado pela soma dos dois termos anteriores. 
Alguns termos dessa sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34. */

#include <stdio.h>

int main(void) {

    int num;
    int seq = 0, seqA = 1, seqAux;

    printf("quantos termos da sequencia de Fibonacci deseja ver? ");
    scanf("%d", &num);

    printf("\n0 ");

    for (int i = 1; i < num; i++) {
        printf("%d ", seqA);
        seqAux = seq;
        seq += seqA;
        seqA = seqAux;
    }

    printf("\n\n");

    return 0;
}
