#include <stdio.h>
#include <string.h>

#define N 100
#define M 4

int main()
{

    char nomes[N][60];
    int id[N];
    int notas[N][M];
    int faltas[N];
    float media[N];

    int totalAlunos = 0;
    int opcao, i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            notas[i][j] = -1;
        }
        faltas[i] = 0;
        media[i] = 0;
    }

    do
    {
        printf("\n===== Sistema de controle academico =====\n");
        printf("\n===== MENU =====\n");
        printf("1. Cadastrar alunos\n");
        printf("2. Lancar notas\n");
        printf("3. Lancar faltas\n");
        printf("4. Listar alunos (resumo)\n");
        printf("5. Boletim completo\n");
        printf("6. Estatisticas\n");
        printf("7. Ranking Top 5\n");
        printf("8. Sair\n");
        printf("Escolha uma das opcoes acima: ");

        while (scanf("%d", &opcao) != 1)
        {
            printf("Entrada invalida! Digite numero: ");
            while (getchar() != '\n')
                ;
        }

        switch (opcao)
        {
        case 1:
        {
            int q, k;

            printf("Quantos alunos deseja cadastrar? ");
            while (scanf("%d", &q) != 1)
            {
                printf("Entrada invalida! Digite apenas numeros: ");
                while (getchar() != '\n')
                    ;
            }

            for (int cont = 0; cont < q && totalAlunos < N; cont++)
            {
                printf("\n Cadastro do Aluno %d \n", totalAlunos + 1);

                int idValido = 0;
                while (!idValido)
                {
                    printf("ID: ");
                    if (scanf("%d", &id[totalAlunos]) != 1)
                    {
                        printf("Erro: Digite apenas numeros!\n");
                        while (getchar() != '\n')
                            ;
                    }
                    else if (id[totalAlunos] <= 0)
                    {
                        printf("Erro: ID deve ser maior que zero!\n");
                    }
                    else
                    {
                        idValido = 1;

                        for (k = 0; k < totalAlunos; k++)
                        {
                            if (id[k] == id[totalAlunos])
                            {
                                printf("Erro: Este ID ja esta cadastrado!\n");
                                idValido = 0;
                            }
                        }
                    }
                }

                int nomeValido = 0;

                while (!nomeValido)
                {
                    printf("Digite o nome: ");

                    while (getchar() != '\n')
                        ;
                    fgets(nomes[totalAlunos], 60, stdin);
                    nomes[totalAlunos][strcspn(nomes[totalAlunos], "\n")] = '\0';

                    nomeValido = 1;

                    if (strlen(nomes[totalAlunos]) == 0)
                    {
                        printf("Nome nao pode ser vazio!\n");
                        nomeValido = 0;
                    }

                    for (k = 0; nomes[totalAlunos][k] != '\0'; k++)
                    {
                        if (!((nomes[totalAlunos][k] >= 'A' && nomes[totalAlunos][k] <= 'Z') ||
                              (nomes[totalAlunos][k] >= 'a' && nomes[totalAlunos][k] <= 'z') ||
                              nomes[totalAlunos][k] == ' '))
                        {
                            nomeValido = 0;
                        }
                    }

                    if (!nomeValido)
                        printf("Nome invalido! Use apenas letras e espacos.\n");
                }

                for (j = 0; j < M; j++)
                {
                    notas[totalAlunos][j] = -1;
                }

                faltas[totalAlunos] = 0;
                media[totalAlunos] = 0;

                totalAlunos++;
            }

            if (totalAlunos >= N)
            {
                printf("\nCapacidade maxima da turma atingida (%d alunos).\n", N);
            }

            printf("Aluno(s) cadastrado(s) com sucesso!\n");
        }
        break;

        case 2:
        {
            int busca, pos = -1;
            printf("Digite o ID do aluno: ");
            while (scanf("%d", &busca) != 1)
            {
                printf("Digite numero valido: ");
                while (getchar() != '\n')
                    ;
            }

            for (i = 0; i < totalAlunos; i++)
            {
                if (id[i] == busca)
                {
                    pos = i;
                }
            }

            if (pos == -1)
            {
                printf("Aluno nao encontrado!\n");
            }
            else
            {

                int soma = 0;

                for (j = 0; j < M; j++)
                {
                    int valido = 0;
                    while (!valido)
                    {
                        printf("Nota %d (0-100): ", j + 1);
                        if (scanf("%d", &notas[pos][j]) != 1)
                        {
                            printf("Digite apenas numeros!\n");
                            while (getchar() != '\n')
                                ;
                        }
                        else if (notas[pos][j] < 0 || notas[pos][j] > 100)
                        {
                            printf("Nota invalida!\n");
                        }
                        else
                        {
                            soma += notas[pos][j];
                            valido = 1;
                        }
                    }
                }

                media[pos] = soma / 4.0;
            }
        }
        break;

        case 3:
        {
            int busca, pos = -1;
            printf("Digite o ID do aluno: ");
            while (scanf("%d", &busca) != 1)
            {
                printf("Digite numero valido: ");
                while (getchar() != '\n')
                    ;
            }

            for (i = 0; i < totalAlunos; i++)
            {
                if (id[i] == busca)
                {
                    pos = i;
                }
            }

            if (pos == -1)
            {
                printf("Aluno nao encontrado!\n");
            }
            else
            {
                int valido = 0;
                while (!valido)
                {
                    printf("Faltas (0-100): ");
                    if (scanf("%d", &faltas[pos]) != 1)
                    {
                        printf("Digite apenas numeros!\n");
                        while (getchar() != '\n')
                            ;
                    }
                    else if (faltas[pos] < 0 || faltas[pos] > 100)
                    {
                        printf("Valor invalido!\n");
                    }
                    else
                    {
                        valido = 1;
                    }
                }
            }
        }
        break;

        case 4:
            printf("\nLISTA DE ALUNOS\n");

            for (i = 0; i < totalAlunos; i++)
            {
                printf("\n--------------------------------------------------\n");
                printf("ID: %-5d | Nome: %-20s\n", id[i], nomes[i]);

                if (notas[i][0] == -1)
                {
                    printf("Media: INCOMPLETO\n");
                    printf("Faltas: %d\n", faltas[i]);
                    printf("Situacao: SEM NOTAS\n");
                }
                else
                {
                    printf("Media: %.2f\n", media[i]);
                    printf("Faltas: %d\n", faltas[i]);

                    if (media[i] >= 60 && faltas[i] <= 25)
                        printf("Situacao: APROVADO\n");
                    else
                        printf("Situacao: REPROVADO\n");
                }
            }
            break;

        case 5:
        {
            int busca, pos = -1;
            printf("Digite o ID: ");
            while (scanf("%d", &busca) != 1)
            {
                printf("Digite numero valido: ");
                while (getchar() != '\n')
                    ;
            }

            for (i = 0; i < totalAlunos; i++)
            {
                if (id[i] == busca)
                {
                    pos = i;
                }
            }

            if (pos == -1)
            {
                printf("Aluno nao encontrado!\n");
            }
            else
            {
                printf("\nID: %d", id[pos]);
                printf("\nNome: %s", nomes[pos]);

                for (j = 0; j < M; j++)
                {
                    printf("\nNota %d: %d", j + 1, notas[pos][j]);
                }

                printf("\nMedia: %.2f", media[pos]);
                printf("\nFaltas: %d", faltas[pos]);

                if (notas[pos][0] == -1)
                {
                    printf("\nSituacao: Sem notas\n");
                }
                else if (media[pos] >= 60 && faltas[pos] <= 25)
                {
                    printf("\nSituacao: Aprovado\n");
                }
                else if (media[pos] < 60 && faltas[pos] > 25)
                {
                    printf("\nSituacao: Reprovado por nota e falta\n");
                }
                else if (media[pos] < 60)
                {
                    printf("\nSituacao: Reprovado por nota\n");
                }
                else
                {
                    printf("\nSituacao: Reprovado por falta\n");
                }
            }
        }
        break;
        case 6:
        {
            float somaTurma = 0;
            int aprov = 0, rNota = 0, rFalta = 0, rAmbos = 0, incompletos = 0, contCompletos = 0;
            int idMaior = -1, idMenor = -1;
            float maiorMed = -1, menorMed = 101;

            for (i = 0; i < totalAlunos; i++)
            {
                if (notas[i][0] == -1)
                {
                    incompletos++;
                }
                else
                {
                    somaTurma += media[i];
                    contCompletos++;

                    if (media[i] > maiorMed)
                    {
                        maiorMed = media[i];
                        idMaior = i;
                    }
                    if (media[i] < menorMed)
                    {
                        menorMed = media[i];
                        idMenor = i;
                    }

                    if (media[i] >= 60 && faltas[i] <= 25)
                        aprov++;
                    else if (media[i] < 60 && faltas[i] > 25)
                        rAmbos++;
                    else if (media[i] < 60)
                        rNota++;
                    else
                        rFalta++;
                }
            }

            if (contCompletos > 0)
            {
                printf("\n--- Estatisticas da Turma ---");
                printf("\nMedia geral: %.2f", somaTurma / contCompletos);
                printf("\nMaior media: %.2f (Aluno: %s, ID: %d)", maiorMed, nomes[idMaior], id[idMaior]);
                printf("\nMenor media: %.2f (Aluno: %s, ID: %d)", menorMed, nomes[idMenor], id[idMenor]);

                printf("\nPercentual Aprovados: %.1f%%", (aprov * 100.0) / contCompletos);
                printf("\nPercentual Reprovados (Nota): %.1f%%", (rNota * 100.0) / contCompletos);
                printf("\nPercentual Reprovados (Falta): %.1f%%", (rFalta * 100.0) / contCompletos);
                printf("\nPercentual Reprovados (Ambos): %.1f%%", (rAmbos * 100.0) / contCompletos);
            }
            printf("\nAlunos com notas incompletas: %d\n", incompletos);
        }
        break;

        case 7:
        {
            int ordem[N], nCompletos = 0;

            for (i = 0; i < totalAlunos; i++)
            {
                if (notas[i][0] != -1)
                {
                    ordem[nCompletos] = i;
                    nCompletos++;
                }
            }

            for (i = 0; i < nCompletos - 1; i++)
            {
                for (j = i + 1; j < nCompletos; j++)
                {
                    if (media[ordem[j]] > media[ordem[i]])
                    {
                        int temp = ordem[i];
                        ordem[i] = ordem[j];
                        ordem[j] = temp;
                    }
                }
            }
            printf("\n===== TOP 5 MEDIAS (COMPLETOS) =====\n");
            for (i = 0; i < 5 && i < nCompletos; i++)
            {
                printf("%d. %s - Media: %.2f\n", i + 1, nomes[ordem[i]], media[ordem[i]]);
            }
        }
        break;

        case 8:
            printf("Encerrando...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 8);

    return 0;
}