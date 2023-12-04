/*✓ Exibir a quantidade de votos que cada jogadora recebeu.

✓ Exibir a jogadora mais votada (caso aconteça empate entre mais de uma jogadora, deverá mostrar todas as que empataram).

✓ Exibir o nome, idade e sexo de todas as pessoas que participaram da pesquisa, separando por sexo, maior de idade e menor de idade.

✓ Exibir o nome das pessoas maior de idade que votaram na Marta Vieira.

 ✓ Exibir a quantidade de mulheres que participaram da pesquisa.*/

 #include <stdio.h>

struct Entrevistado
{
    char nome;
    int idade;
    char genero;
    char voto;
};

char jogadoras()
{
    printf("qual das jogadoras listadas na tabela abaixo e considerada a melhor?\n");
    printf("opcao 1: sam kerr - australia\n");
    printf("opcao 2: alex morgan - estados unidos\n");
    printf("opcao 3: dzsenifer marozsan - alemanha\n");
    printf("opcao 4: amandine henzy - franca\n");
    printf("opcao 5: marta vieira - brasil\n");

    char opcao;
    printf("opcao: ");
    scanf(" %c", &opcao);

    return opcao;
}

int main()
{
    int entrevistados = 0;

    while (1)
    {
        printf("digite o numero de entrevistados (entre 50 e 300): ");
        scanf("%d", &entrevistados);
        if (entrevistados >= 50 && entrevistados <= 300)
        {
            break;
        }
        else
        {
            printf("o numero de entrevistados deve estar entre 50 e 300.\n");
        }
    }

    struct Entrevistado dados[entrevistados];

    for (int i = 0; i < entrevistados; i++)
    {
        printf("ficha do entrevistado %d:\n", i + 1);
        printf("digite seu nome: ");
        scanf(" %c", &dados[i].nome);
        printf("digite sua idade (maior que 12 anos): ");
        scanf("%d", &dados[i].idade);

        if (dados[i].idade <= 12)
        {
            printf("sua idade nao atende aos criterios (menor ou igual a 12 anos).\n");
            i--;
            continue;
        }

        printf("digite seu genero (M para masculino e F para feminino): ");
        scanf(" %c", &dados[i].genero);

        if (dados[i].genero == 'M' || dados[i].genero == 'm')
        {
            printf("voce selecionou masculino.\n");
        }
        else if (dados[i].genero == 'F' || dados[i].genero == 'f')
        {
            printf("voce selecionou feminino.\n");
        }
        else
        {
            printf("genero nao reconhecido.\n");
            i--;
            continue;
        }

        dados[i].voto = jogadoras();
    }
    /*contar votos*/
    int contarVotos[5] = {0};

    printf("\nquantidade de votos para cada jogadora:\n");
    for (int i = 0; i < entrevistados; i++)
    {
        contarVotos[dados[i].voto - '0' - 1]++;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("jogadora %d: %d votos\n", i + 1, contarVotos[i]);
    }
    /*jogadora mais votada*/
    int maisVotos = 0;
    printf("\njogadoras mais votadas:\n");
    for (int i = 0; i < 5; i++)
    {
        if (contarVotos[i] > maisVotos)
        {
            maisVotos = contarVotos[i];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (contarVotos[i] == maisVotos)
        {
            printf("jogadora %d: %d votos\n", i + 1, maisVotos);
        }
    }
    /*exibir nome, idade e genero dos homens e mulheres que participaram da pesquisa*/
    printf("\nmulheres:\n");
    for (int i = 0; i < entrevistados; i++)
    {
        if (dados[i].genero == 'F' || dados[i].genero == 'f')
        {
            printf("nome: %c, idade: %d, genero: %c\n", dados[i].nome, dados[i].idade, dados[i].genero);
        }
    }

    printf("\nhomens:\n");
    for (int i = 0; i < entrevistados; i++)
    {
        if (dados[i].genero == 'M' || dados[i].genero == 'm')
        {
            printf("nome: %c, idade: %d, genero: %c\n", dados[i].nome, dados[i].idade, dados[i].genero);
        }
    }

    printf("\nmaiores de idade:\n");
    for (int i = 0; i < entrevistados; i++)
    {
        if (dados[i].idade > 12)
        {
            printf("nome: %c, idade: %d, genero: %c\n", dados[i].nome, dados[i].idade, dados[i].genero);
        }
    }

    printf("\nmenores de idade:\n");
    for (int i = 0; i < entrevistados; i++)
    {
        if (dados[i].idade <= 12)
        {
            printf("nome: %c, idade: %d, genero: %c\n", dados[i].nome, dados[i].idade, dados[i].genero);
        }
    }
    /*exibir pessoas maiores de idade que votaram na Marta Vieira*/
    printf("\npessoas maiores de idade que votaram na Marta Vieira:\n");
    for (int i = 0; i < entrevistados; i++)
    {
        if (dados[i].idade > 12 && dados[i].voto == '5')
        {
            printf("nome: %c\n", dados[i].nome);
        }
    }
    /*exibir a quantidade de mulheres que participaram da pesquisa*/
    int contarMulheresParticipantes = 0;
    for (int i = 0; i < entrevistados; i++)
    {
        if (dados[i].genero == 'F' || dados[i].genero == 'f')
        {
            contarMulheresParticipantes++;
        }
    }
    printf("\nquantidade de mulheres que participaram da pesquisa: %d\n", contarMulheresParticipantes);

    return 0;
}
