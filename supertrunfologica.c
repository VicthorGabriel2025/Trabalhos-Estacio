#include <stdio.h>
#include <string.h>

// Variáveis globais
char estado1, estado2;
char codigo1[5], codigo2[5];
char nome1[30], nome2[30];
unsigned long int populacao1, populacao2;
float area1, area2;
float PIB1, PIB2;
int Pontos_Turisticos1, Pontos_Turisticos2;
float Densidade_Populacional1, Densidade_Populacional2;
float PIB_Capita1, PIB_Capita2;
float SuperPoder1, SuperPoder2;

void Cadastro_de_Cartas() {
    printf("Cadastro da Primeira Carta:\n");
    printf("Digite uma letra de 'A' a 'H':\n");
    scanf(" %c", &estado1);
    printf("Digite o codigo da carta:\n");
    scanf("%s", codigo1);
    printf("Digite o nome da cidade:\n");
    scanf(" %[^\n]", nome1);  
    printf("Digite o numero de habitantes:\n");
    scanf("%lu", &populacao1);
    printf("Digite a area da cidade:\n");
    scanf("%f", &area1);
    printf("Digite o PIB:\n");
    scanf("%f", &PIB1);
    printf("Digite a quantidade de pontos turisticos:\n");
    scanf("%d", &Pontos_Turisticos1);

    printf("\nCadastro da Segunda Carta:\n");
    printf("Digite uma letra de 'A' a 'H':\n");
    scanf(" %c", &estado2);
    printf("Digite o codigo da carta:\n");
    scanf("%s", codigo2);
    printf("Digite o nome da cidade:\n");
    scanf(" %[^\n]", nome2);
    printf("Digite o numero de habitantes:\n");
    scanf("%lu", &populacao2);
    printf("Digite a area da cidade:\n");
    scanf("%f", &area2);
    printf("Digite o PIB:\n");
    scanf("%f", &PIB2);
    printf("Digite a quantidade de pontos turisticos:\n");
    scanf("%d", &Pontos_Turisticos2);
}

void Calculos() {
    Densidade_Populacional1 = populacao1 / area1;
    Densidade_Populacional2 = populacao2 / area2;
    PIB_Capita1 = PIB1 / populacao1;
    PIB_Capita2 = PIB2 / populacao2;

    float inverso_densidade1 = 1 / Densidade_Populacional1;
    float inverso_densidade2 = 1 / Densidade_Populacional2;

    SuperPoder1 = populacao1 + area1 + PIB1 + Pontos_Turisticos1 + PIB_Capita1 + inverso_densidade1;
    SuperPoder2 = populacao2 + area2 + PIB2 + Pontos_Turisticos2 + PIB_Capita2 + inverso_densidade2;
}

void Exibicao_de_Resultados() {
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome: %s\n", nome1);
    printf("População: %lu\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões\n", PIB1);
    printf("Pontos Turisticos: %d\n", Pontos_Turisticos1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome: %s\n", nome2);
    printf("População: %lu\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões\n", PIB2);
    printf("Pontos Turisticos: %d\n", Pontos_Turisticos2);

    printf("\nDensidade Populacional Carta 1: %.2f hab/km²\n", Densidade_Populacional1);
    printf("Densidade Populacional Carta 2: %.2f hab/km²\n", Densidade_Populacional2);

    printf("\nPIB per capita Carta 1: %.6f reais\n", PIB_Capita1);
    printf("PIB per capita Carta 2: %.6f reais\n", PIB_Capita2);

    printf("\nSuper Poder Carta 1: %.6f\n", SuperPoder1);
    printf("Super Poder Carta 2: %.6f\n", SuperPoder2);
}

void Menu_Comparacao() {
    int opcao;
    printf("\nEscolha o atributo para comparar entre as cartas:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("6 - Sair\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: // Populacao
            printf("\nComparando Populacao:\n");
            printf("%s: %lu\n", nome1, populacao1);
            printf("%s: %lu\n", nome2, populacao2);
            if (populacao1 > populacao2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nome1);
            } else if (populacao2 > populacao1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nome2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 2: // Area
            printf("\nComparando Area:\n");
            printf("%s: %.2f km²\n", nome1, area1);
            printf("%s: %.2f km²\n", nome2, area2);
            if (area1 > area2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nome1);
            } else if (area2 > area1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nome2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 3: // PIB
            printf("\nComparando PIB:\n");
            printf("%s: %.2f bilhões\n", nome1, PIB1);
            printf("%s: %.2f bilhões\n", nome2, PIB2);
            if (PIB1 > PIB2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nome1);
            } else if (PIB2 > PIB1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nome2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 4: // Pontos Turisticos
            printf("\nComparando Pontos Turisticos:\n");
            printf("%s: %d\n", nome1, Pontos_Turisticos1);
            printf("%s: %d\n", nome2, Pontos_Turisticos2);
            if (Pontos_Turisticos1 > Pontos_Turisticos2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nome1);
            } else if (Pontos_Turisticos2 > Pontos_Turisticos1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nome2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 5: // Densidade Demografica (inverte a regra)
            printf("\nComparando Densidade Demografica (menor vence):\n");
            printf("%s: %.2f hab/km²\n", nome1, Densidade_Populacional1);
            printf("%s: %.2f hab/km²\n", nome2, Densidade_Populacional2);
            if (Densidade_Populacional1 < Densidade_Populacional2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nome1);
            } else if (Densidade_Populacional2 < Densidade_Populacional1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nome2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 6:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
    }
}

int main() {
    Cadastro_de_Cartas();
    Calculos();
    Exibicao_de_Resultados();

    int continuar = 1;
    while (continuar) {
        Menu_Comparacao();
        printf("\nDeseja comparar outro atributo? (1 - Sim / 0 - Nao): ");
        scanf("%d", &continuar);
    }

    printf("Programa finalizado.\n");
    return 0;
}
