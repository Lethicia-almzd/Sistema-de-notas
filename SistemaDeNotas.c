#include <stdio.h>
#include <string.h>

#define N 40
#define M 4

int main()
{
    char nomes[N][60];
    int id[N];
    int notas[N][M];
    int faltas[N];
    float media[N];

    int totalAlunos = 0;
    int opcao = 0;
    int i, j;

    for (i = 0; i < N; i++)
    {
        id[i] = -1;
        faltas[i] = 0;
        media[i] = 0;
        for (j = 0; j < M; j++)
            notas[i][j] = -1;
    }

    do
    {
        printf("\n===== SISTEMA DE GERENCIAMENTO DE TURMA =====\n");
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1. Cadastrar alunos\n");
        printf("2. Lancar notas\n");
        printf("3. Lancar faltas\n");
        printf("4. Listar alunos\n");
        printf("5. Boletim completo\n");
        printf("6. Estatisticas da turma\n");
        printf("7. Ranking Top 5\n");
        printf("8. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:
        {
            int q, k, idValido, repetido;

            printf("\nQuantos alunos deseja cadastrar? ");
            scanf("%d", &q);

            if (q < 1 || q > N - totalAlunos)
                printf("\nQuantidade invalida ou limite excedido!\n");
            else
            {
                for (k = 0; k < q; k++)
                {
                    printf("\nCadastro do aluno %d\n", totalAlunos + 1);

                    idValido = 0;
                    while (idValido == 0)
                    {
                        printf("Digite o ID: ");
                        scanf("%d", &id[totalAlunos]);

                        if (id[totalAlunos] <= 0)
                            printf("ID invalido!\n");
                        else
                        {
                            repetido = 0;
                            for (i = 0; i < totalAlunos; i++)
                                if (id[i] == id[totalAlunos])
                                    repetido = 1;

                            if (repetido == 1)
                                printf("ID ja existe!\n");
                            else
                                idValido = 1;
                        }
                    }

                    printf("Digite o nome: ");
                    scanf(" %[^\n]", nomes[totalAlunos]);

                    for (j = 0; j < M; j++)
                        notas[totalAlunos][j] = -1;

                    faltas[totalAlunos] = 0;
                    media[totalAlunos] = 0;

                    totalAlunos++;
                }
            }
            break;
        }

        case 2:
        {
            int idProcurado, encontrado = -1;

            if (totalAlunos == 0)
                printf("\nNenhum aluno cadastrado!\n");
            else
            {
                printf("\nDigite o ID do aluno: ");
                scanf("%d", &idProcurado);

                for (i = 0; i < totalAlunos; i++)
                    if (id[i] == idProcurado && encontrado == -1)
                        encontrado = i;

                if (encontrado == -1)
                    printf("Aluno nao encontrado!\n");
                else
                {
                    printf("Aluno: %s\n", nomes[encontrado]);

                    for (j = 0; j < M; j++)
                    {
                        int valido = 0;
                        while (valido == 0)
                        {
                            printf("Digite a nota %d (0 a 100): ", j + 1);
                            scanf("%d", &notas[encontrado][j]);

                            if (notas[encontrado][j] >= 0 && notas[encontrado][j] <= 100)
                                valido = 1;
                            else
                                printf("Nota invalida!\n");
                        }
                    }
                }
            }
            break;
        }

        case 3:
        {
            int idProcurado, encontrado = -1;

            if (totalAlunos == 0)
                printf("\nNenhum aluno cadastrado!\n");
            else
            {
                printf("\nDigite o ID do aluno: ");
                scanf("%d", &idProcurado);

                for (i = 0; i < totalAlunos; i++)
                    if (id[i] == idProcurado && encontrado == -1)
                        encontrado = i;

                if (encontrado == -1)
                    printf("Aluno nao encontrado!\n");
                else
                {
                    int valido = 0;
                    while (valido == 0)
                    {
                        printf("Digite as faltas (0 a 100): ");
                        scanf("%d", &faltas[encontrado]);

                        if (faltas[encontrado] >= 0 && faltas[encontrado] <= 100)
                            valido = 1;
                        else
                            printf("Valor invalido!\n");
                    }
                }
            }
            break;
        }

        case 4:
        {
            if (totalAlunos == 0)
                printf("\nNenhum aluno cadastrado.\n");
            else
            {
                for (i = 0; i < totalAlunos; i++)
                {
                    int completo = 1;
                    float soma = 0;

                    for (j = 0; j < M; j++)
                        if (notas[i][j] == -1)
                            completo = 0;
                        else
                            soma += notas[i][j];

                    printf("\nID: %d\nNome: %s\nFaltas: %d\n", id[i], nomes[i], faltas[i]);

                    if (completo == 0)
                        printf("Media: INCOMPLETO\n");
                    else
                    {
                        media[i] = soma / M;
                        printf("Media: %.2f\n", media[i]);
                    }
                }
            }
            break;
        }

        case 5:
        {
            int busca, pos = -1;

            printf("\nDigite o ID do aluno: ");
            scanf("%d", &busca);

            for (i = 0; i < totalAlunos; i++)
                if (id[i] == busca && pos == -1)
                    pos = i;

            if (pos == -1)
                printf("Aluno nao encontrado.\n");
            else
            {
                float soma = 0;
                int completo = 1;

                printf("\nID: %d\nNome: %s\n", id[pos], nomes[pos]);

                for (j = 0; j < M; j++)
                {
                    if (notas[pos][j] == -1)
                    {
                        printf("Nota %d: NAO LANCADA\n", j + 1);
                        completo = 0;
                    }
                    else
                    {
                        printf("Nota %d: %d\n", j + 1, notas[pos][j]);
                        soma += notas[pos][j];
                    }
                }

                printf("Faltas: %d\n", faltas[pos]);

                if (completo == 1)
                {
                    media[pos] = soma / M;
                    printf("Media: %.2f\n", media[pos]);
                }
                else
                    printf("Media: INCOMPLETO\n");
            }
            break;
        }

        case 6:
        {
            if (totalAlunos == 0)
                printf("\nNenhum aluno cadastrado.\n");
            else
            {
                float somaMedias = 0;
                int completos = 0, incompletos = 0;
                float maior = -1, menor = 101;
                int posMaior = -1, posMenor = -1;

                int aprov = 0, repNota = 0, repFalta = 0, repAmbos = 0;

                for (i = 0; i < totalAlunos; i++)
                {
                    int completo = 1;
                    float soma = 0;

                    for (j = 0; j < M; j++)
                    {
                        if (notas[i][j] == -1)
                            completo = 0;
                        else
                            soma += notas[i][j];
                    }

                    if (completo == 1)
                    {
                        media[i] = soma / M;
                        somaMedias += media[i];
                        completos++;

                        if (media[i] > maior)
                        {
                            maior = media[i];
                            posMaior = i;
                        }

                        if (media[i] < menor)
                        {
                            menor = media[i];
                            posMenor = i;
                        }

                        if (media[i] >= 60 && faltas[i] <= 25)
                            aprov++;
                        else if (media[i] < 60 && faltas[i] > 25)
                            repAmbos++;
                        else if (media[i] < 60)
                            repNota++;
                        else
                            repFalta++;
                    }
                    else
                        incompletos++;
                }

                if (completos > 0)
                {
                    printf("\nMedia geral: %.2f\n", somaMedias / completos);

                    printf("\nMaior media: %.2f\n", maior);
                    printf("ID: %d Nome: %s\n", id[posMaior], nomes[posMaior]);

                    printf("\nMenor media: %.2f\n", menor);
                    printf("ID: %d Nome: %s\n", id[posMenor], nomes[posMenor]);

                    printf("\nPercentual aprovados: %.2f%%\n", (aprov * 100.0) / completos);
                    printf("Reprovados por nota: %.2f%%\n", (repNota * 100.0) / completos);
                    printf("Reprovados por falta: %.2f%%\n", (repFalta * 100.0) / completos);
                    printf("Reprovados por ambos: %.2f%%\n", (repAmbos * 100.0) / completos);
                }

                printf("Incompletos: %d\n", incompletos);
            }
            break;
        }

        case 7:
        {
            int usados[N] = {0};
            int count = 0;

            for (i = 0; i < totalAlunos; i++)
            {
                int completo = 1;
                float soma = 0;

                for (j = 0; j < M; j++)
                {
                    if (notas[i][j] == -1)
                        completo = 0;
                    else
                        soma += notas[i][j];
                }

                if (completo == 1)
                {
                    media[i] = soma / M;
                }
            }

            printf("\n===== TOP 5 =====\n");

            while (count < 5)
            {
                float maior = -1;
                int pos = -1;

                for (i = 0; i < totalAlunos; i++)
                {
                    int completo = 1;

                    for (j = 0; j < M; j++)
                        if (notas[i][j] == -1)
                            completo = 0;

                    if (completo == 1 && usados[i] == 0 && media[i] > maior)
                    {
                        maior = media[i];
                        pos = i;
                    }
                }

                if (pos == -1)
                    count = 5;
                else
                {
                    printf("\n%d° Lugar\n", count + 1);
                    printf("ID: %d\nNome: %s\nMedia: %.2f\n", id[pos], nomes[pos], media[pos]);

                    usados[pos] = 1;
                    count++;
                }
            }
            break;
        }

        case 8:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 8);

    return 0;
}