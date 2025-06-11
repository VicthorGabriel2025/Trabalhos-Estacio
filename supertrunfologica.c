#include <stdio.h>
#include <string.h>

// Variaveis globais
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

// Funcao para mostrar o nome do atributo dado o código
const char* nome_atributo(int opcao) {
    switch(opcao) {
        case 1: return "Populacao";
        case 2: return "area";
        case 3: return "PIB";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Demografica";
        default: return "";
    }
}

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
    printf("Populacao: %lu\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões\n", PIB1);
    printf("Pontos Turisticos: %d\n", Pontos_Turisticos1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome: %s\n", nome2);
    printf("Populacao: %lu\n", populacao2);
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

// Funcao para ler a escolha do atributo, removendo o ja escolhido
int escolher_atributo(int atributo_excluido) {
    int opcao;
    while (1) {
        printf("\nEscolha um atributo para comparacao:\n");
        if (atributo_excluido != 1) printf("1 - Populacao\n");
        if (atributo_excluido != 2) printf("2 - area\n");
        if (atributo_excluido != 3) printf("3 - PIB\n");
        if (atributo_excluido != 4) printf("4 - Pontos Turisticos\n");
        if (atributo_excluido != 5) printf("5 - Densidade Demografica\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        if (opcao >=1 && opcao <=5 && opcao != atributo_excluido) {
            return opcao;
        } else {
            printf("Opcao invalida ou ja escolhida. Tente novamente.\n");
        }
    }
}

// Funcao para obter valor do atributo para uma carta
float obter_valor_atributo(int atributo, int carta) {
    // carta == 1 -> carta 1, else carta 2
    switch(atributo) {
        case 1: return carta == 1 ? (float)populacao1 : (float)populacao2;
        case 2: return carta == 1 ? area1 : area2;
        case 3: return carta == 1 ? PIB1 : PIB2;
        case 4: return carta == 1 ? (float)Pontos_Turisticos1 : (float)Pontos_Turisticos2;
        case 5: return carta == 1 ? Densidade_Populacional1 : Densidade_Populacional2;
        default: return 0;
    }
}

// Funcao para imprimir valor formatado do atributo, com diferenca para densidade e populacao grande
void imprimir_valor_atributo(int atributo, float valor) {
    switch(atributo) {
        case 1: printf("%.0f habitantes", valor); break;
        case 2: printf("%.2f km²", valor); break;
        case 3: printf("%.2f bilhões", valor); break;
        case 4: printf("%.0f pontos", valor); break;
        case 5: printf("%.2f hab/km²", valor); break;
    }
}

// Funcao que compara um atributo e retorna qual carta venceu: 1, 2 ou 0 para empate
int comparar_atributo(int atributo) {
    float val1 = obter_valor_atributo(atributo, 1);
    float val2 = obter_valor_atributo(atributo, 2);

    // Para Densidade Demografica, menor vence
    if (atributo == 5) {
        if (val1 < val2) return 1;
        else if (val2 < val1) return 2;
        else return 0;
    } else {
        if (val1 > val2) return 1;
        else if (val2 > val1) return 2;
        else return 0;
    }
}

void Menu_Comparacao_Dupla() {
    printf("\nEscolha o primeiro atributo para comparacao:\n");
    int attr1 = escolher_atributo(0);

    printf("\nEscolha o segundo atributo para comparacao (diferente do primeiro):\n");
    int attr2 = escolher_atributo(attr1);

    // Obter valores
    float val1_attr1 = obter_valor_atributo(attr1, 1);
    float val2_attr1 = obter_valor_atributo(attr1, 2);
    float val1_attr2 = obter_valor_atributo(attr2, 1);
    float val2_attr2 = obter_valor_atributo(attr2, 2);

    // Comparar os atributos
    int vencedor_attr1 = comparar_atributo(attr1);
    int vencedor_attr2 = comparar_atributo(attr2);

    // Soma dos valores (regra: soma normal, mesmo para densidade)
    float soma1 = val1_attr1 + val1_attr2;
    float soma2 = val2_attr1 + val2_attr2;

    printf("\n--- Resultado da Comparacao ---\n");
    printf("Cartas: %s vs %s\n\n", nome1, nome2);

    printf("Atributos comparados:\n");
    printf("1) %s:\n", nome_atributo(attr1));
    printf("   %s: ", nome1);
    imprimir_valor_atributo(attr1, val1_attr1);
    printf("\n   %s: ", nome2);
    imprimir_valor_atributo(attr1, val2_attr1);
    printf("\n   Vencedor deste atributo: %s\n\n",
        vencedor_attr1 == 0 ? "Empate" : (vencedor_attr1 == 1 ? nome1 : nome2));

    printf("2) %s:\n", nome_atributo(attr2));
    printf("   %s: ", nome1);
    imprimir_valor_atributo(attr2, val1_attr2);
    printf("\n   %s: ", nome2);
    imprimir_valor_atributo(attr2, val2_attr2);
    printf("\n   Vencedor deste atributo: %s\n\n",
        vencedor_attr2 == 0 ? "Empate" : (vencedor_attr2 == 1 ? nome1 : nome2));

    printf("Soma dos valores:\n");
    printf("   %s: %.2f\n", nome1, soma1);
    printf("   %s: %.2f\n", nome2, soma2);

    if (soma1 > soma2)
        printf("\nResultado final: Carta 1 (%s) venceu!\n", nome1);
    else if (soma2 > soma1)
        printf("\nResultado final: Carta 2 (%s) venceu!\n", nome2);
    else
        printf("\nResultado final: Empate!\n");
}

int main() {
    Cadastro_de_Cartas();
    Calculos();
    Exibicao_de_Resultados();

    int continuar = 1;
    while (continuar) {
        Menu_Comparacao_Dupla();
        printf("\nDeseja comparar outros atributos? (1 - Sim / 0 - Nao): ");
        scanf("%d", &continuar);
    }

    printf("Programa finalizado.\n");
    return 0;
}
