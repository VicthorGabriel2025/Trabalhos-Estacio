#include <stdio.h>

// Declarando as variáveis globais para que possam ser utilizadas em outras áreas do codigo
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



/*Aqui são cadastradas as informações pedidas em relação às duas cartas que serão utilizadas até o momento.*/
void Cadastro_de_Cartas() {
    printf("Cadastro da Primeira Carta:\n");
    printf("Digite uma letra de 'A' a 'H':\n");
    scanf(" %c", &estado1);
    printf("Digite o codigo da carta:\n");
    scanf("%s", codigo1);
    printf("Digite o nome da cidade:\n");
    scanf(" %[^\n]", nome1);  
    printf("Digite o numero de habitantes:\n");
    scanf("%lu", &populacao1); // Alteração: %lu para ler unsigned long int
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
    scanf("%lu", &populacao2); // Alteração: %lu para ler unsigned long int
    printf("Digite a area da cidade:\n");
    scanf("%f", &area2);
    printf("Digite o PIB:\n");
    scanf("%f", &PIB2);
    printf("Digite a quantidade de pontos turisticos:\n");
    scanf("%d", &Pontos_Turisticos2);
}

//Uma função especifica para o calculo das informações adicionadas no desafio nível aventureiro
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

//Uma função para mostrar apenas os resultados de todos os calculos, modificações em strings, etc ao longo do processo.
void Exibicao_de_Resultados() {
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome: %s\n", nome1);
    printf("População: %lu\n", populacao1); // Alteração: %lu para unsigned long int
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões\n", PIB1);
    printf("Pontos Turisticos: %d\n", Pontos_Turisticos1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome: %s\n", nome2);
    printf("População: %lu\n", populacao2); // Alteração: %lu para unsigned long int
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

void Comparar_Cartas() {
    printf("\nComparação de Cartas:\n");

    // População
    if (populacao1 > populacao2) {
        printf("População: Carta 1 venceu (1)\n");
    } else {
        printf("População: Carta 2 venceu (0)\n");
    }

    // Área
    if (area1 > area2) {
        printf("Área: Carta 1 venceu (1)\n");
    } else {
        printf("Área: Carta 2 venceu (0)\n");
    }

    // PIB
    if (PIB1 > PIB2) {
        printf("PIB: Carta 1 venceu (1)\n");
    } else {
        printf("PIB: Carta 2 venceu (0)\n");
    }

    // Pontos Turísticos
    if (Pontos_Turisticos1 > Pontos_Turisticos2) {
        printf("Pontos Turísticos: Carta 1 venceu (1)\n");
    } else {
        printf("Pontos Turísticos: Carta 2 venceu (0)\n");
    }

    // Densidade Populacional: a menor vence
    if (Densidade_Populacional1 < Densidade_Populacional2) {
        printf("Densidade Populacional: Carta 1 venceu (1)\n");
    } else {
        printf("Densidade Populacional: Carta 2 venceu (0)\n");
    }

    // PIB per capita
    if (PIB_Capita1 > PIB_Capita2) {
        printf("PIB per Capita: Carta 1 venceu (1)\n");
    } else {
        printf("PIB per Capita: Carta 2 venceu (0)\n");
    }

    // Super Poder
    if (SuperPoder1 > SuperPoder2) {
        printf("Super Poder: Carta 1 venceu (1)\n");
    } else {
        printf("Super Poder: Carta 2 venceu (0)\n");
    }
}

int main() {
    Cadastro_de_Cartas();
    Calculos();
    Exibicao_de_Resultados();
    Comparar_Cartas();
    return 0;}
