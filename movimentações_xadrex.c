#include <stdio.h>

void movimento_torre_rec(int casas, int atual) {
    if (atual > casas) {
        printf("A torre se moveu um total de %d casas para a direita\n\n", casas);
        return;
    }
    printf("Direita\n");
    movimento_torre_rec(casas, atual + 1);
}

void movimento_rainha_rec(int casas, int atual) {
    if (atual > casas) {
        printf("A rainha se moveu um total de %d casas para a esquerda\n\n", casas);
        return;
    }
    printf("Esquerda\n");
    movimento_rainha_rec(casas, atual + 1);
}

void movimento_bispo_rec(int casas_vert, int casas_hor, int atual_vert, int atual_hor) {
    if (atual_vert > casas_vert) {
        printf("O bispo se moveu um total de %d casas para cima e para a direita\n\n", casas_vert);
        return;
    }
    if (atual_hor <= casas_hor) {
        printf("Cima\n");
        printf("Direita\n");
        movimento_bispo_rec(casas_vert, casas_hor, atual_vert, atual_hor + 1);
    } else {
        movimento_bispo_rec(casas_vert, casas_hor, atual_vert + 1, 1);
    }
}

void movimento_cavalo() {
    int movimentos_cima = 2;
    int movimentos_direita = 1;

    for (int cima = 1; cima <= movimentos_cima; cima++) {
        printf("Cima\n");

        if (cima == movimentos_cima) {
            for (int direita = 1; direita <= movimentos_direita; direita++) {
                if (direita > movimentos_direita) {
                    break; 
                }
                if (direita == 0) {
                    continue; 
                }
                printf("Direita\n");
            }
        }
    }

    printf("\n");
}

int main() {
    movimento_torre_rec(5, 1);
    movimento_rainha_rec(8, 1);
    movimento_bispo_rec(5, 5, 1, 1);
    movimento_cavalo();

    return 0;
}

