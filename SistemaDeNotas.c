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
        {
            notas[i][j] = -1;
        }
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
            int q, k;
            int idValido;
            int repetido;

            printf("\nQuantos alunos deseja cadastrar? ");
            scanf("%d", &q);

            if (q < 1 || q > N - totalAlunos)
            {
                printf("\nQuantidade invalida ou limite da turma excedido!\n");
            }
            else
            {
                for (k = 0; k < q; k++)
                {
                    printf("\nCadastro do aluno %d\n", totalAlunos + 1);

                    idValido = 0;
                    while (idValido == 0)
                    {
                        printf("Digite o ID (maior que 0): ");
                        scanf("%d", &id[totalAlunos]);

                        if (id[totalAlunos] <= 0)
                        {
                            printf("ID invalido!\n");
                        }
                        else
                        {
                            repetido = 0;
                            for (i = 0; i < totalAlunos; i++)
                            {
                                if (id[i] == id[totalAlunos])
                                {
                                    repetido = 1;
                                }
                            }

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
                    printf("Aluno cadastrado com sucesso!\n");
                }
            }
            break;
        }

        case 4:
        {
            if (totalAlunos == 0)
            {
                printf("\nNenhum aluno cadastrado.\n");
            }
            else
            {
                printf("\n===== RESUMO DOS ALUNOS =====\n");

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

                    printf("\nID: %d\n", id[i]);
                    printf("Nome: %s\n", nomes[i]);
                    printf("Faltas: %d\n", faltas[i]);

                    if (completo == 0)
                    {
                        printf("Media: INCOMPLETO\n");
                        printf("Situacao: SEM NOTAS\n");
                    }
                    else
                    {
                        media[i] = soma / M;
                        printf("Media: %.2f\n", media[i]);

                        if (media[i] >= 60 && faltas[i] <= 25)
                            printf("Situacao: APROVADO\n");
                        else if (media[i] < 60 && faltas[i] > 25)
                            printf("Situacao: REPROVADO POR NOTA E FALTA\n");
                        else if (media[i] < 60)
                            printf("Situacao: REPROVADO POR NOTA\n");
                        else
                            printf("Situacao: REPROVADO POR FALTA\n");
                    }
                }
            }
            break;
        }

        case 5:
        {
            if (totalAlunos == 0)
            {
                printf("\nNenhum aluno cadastrado.\n");
            }
            else
            {
                int busca, pos = -1;

                printf("\nDigite o ID do aluno: ");
                scanf("%d", &busca);

                for (i = 0; i < totalAlunos; i++)
                {
                    if (id[i] == busca)
                        pos = i;
                }

                if (pos == -1)
                {
                    printf("Aluno nao encontrado.\n");
                }
                else
                {
                    printf("\n===== BOLETIM DO ALUNO =====\n");
                    printf("ID: %d\n", id[pos]);
                    printf("Nome: %s\n", nomes[pos]);

                    int completo = 1;
                    float soma = 0;

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

                    if (completo == 0)
                    {
                        printf("Media: INCOMPLETO\n");
                        printf("Situacao: SEM NOTAS\n");
                    }
                    else
                    {
                        media[pos] = soma / M;
                        printf("Media: %.2f\n", media[pos]);

                        if (media[pos] >= 60 && faltas[pos] <= 25)
                            printf("Situacao: APROVADO\n");
                        else if (media[pos] < 60 && faltas[pos] > 25)
                            printf("Situacao: REPROVADO POR NOTA E FALTA\n");
                        else if (media[pos] < 60)
                            printf("Situacao: REPROVADO POR NOTA\n");
                        else
                            printf("Situacao: REPROVADO POR FALTA\n");
                    }
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