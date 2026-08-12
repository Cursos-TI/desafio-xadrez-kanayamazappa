#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Implementação completa dos três níveis: Novato, Aventureiro e Mestre.

// ============================================================
// NÍVEL MESTRE - Funções Recursivas (declaradas antes do main)
// ============================================================

// Movimenta o Bispo recursivamente na diagonal superior direita.
// Utiliza loops aninhados internamente: externo = eixo vertical (Cima),
// interno = eixo horizontal (Direita). Juntos representam a diagonal.
void moverBispo(int casas) {
    if (casas == 0) return; // caso base: sem casas restantes

    for (int vertical = 0; vertical < 1; vertical++) {       // loop externo: componente Cima
        for (int horizontal = 0; horizontal < 1; horizontal++) { // loop interno: componente Direita
            printf("Cima\n");
            printf("Direita\n");
        }
    }

    moverBispo(casas - 1); // chamada recursiva para a próxima casa
}

// Movimenta a Torre recursivamente para a direita.
void moverTorre(int casas) {
    if (casas == 0) return; // caso base
    printf("Direita\n");
    moverTorre(casas - 1); // chamada recursiva
}

// Movimenta a Rainha recursivamente para a esquerda.
void moverRainha(int casas) {
    if (casas == 0) return; // caso base
    printf("Esquerda\n");
    moverRainha(casas - 1); // chamada recursiva
}

int main() {
    // Constantes para o número de casas de cada peça
    const int CASAS_BISPO  = 5;
    const int CASAS_TORRE  = 5;
    const int CASAS_RAINHA = 8;

    // ============================================================
    // NÍVEL NOVATO
    // Cada peça utiliza uma estrutura de repetição diferente.
    // ============================================================

    // Bispo: 5 casas na diagonal superior direita — loop FOR
    printf("=== Bispo - Nivel Novato ===\n");
    for (int i = 0; i < CASAS_BISPO; i++) {
        printf("Cima\n");
        printf("Direita\n");
    }

    // Torre: 5 casas para a direita — loop WHILE
    printf("\n=== Torre - Nivel Novato ===\n");
    int pTorre = 0;
    while (pTorre < CASAS_TORRE) {
        printf("Direita\n");
        pTorre++;
    }

    // Rainha: 8 casas para a esquerda — loop DO-WHILE
    printf("\n=== Rainha - Nivel Novato ===\n");
    int pRainha = 0;
    do {
        printf("Esquerda\n");
        pRainha++;
    } while (pRainha < CASAS_RAINHA);

    // ============================================================
    // NÍVEL AVENTUREIRO - Cavalo em L (2 baixo + 1 esquerda)
    // Obrigatório: loops aninhados (FOR externo + WHILE interno).
    // ============================================================
    printf("\n=== Cavalo - Nivel Aventureiro ===\n");

    // Loop externo (for): itera sobre as duas fases do movimento em L
    //   fase 0 → 2 casas para baixo
    //   fase 1 → 1 casa para esquerda
    for (int fase = 0; fase < 2; fase++) {
        int passos = (fase == 0) ? 2 : 1;
        int p = 0;
        while (p < passos) { // loop interno (while): executa cada passo da fase
            if (fase == 0) printf("Baixo\n");
            else           printf("Esquerda\n");
            p++;
        }
    }

    // ============================================================
    // NÍVEL MESTRE - Funções recursivas + loop com condições múltiplas
    // ============================================================

    // Bispo: 5 casas diagonal superior direita (função recursiva + loops aninhados)
    printf("\n=== Bispo - Nivel Mestre ===\n");
    moverBispo(CASAS_BISPO);

    // Torre: 5 casas para a direita (função recursiva)
    printf("\n=== Torre - Nivel Mestre ===\n");
    moverTorre(CASAS_TORRE);

    // Rainha: 8 casas para a esquerda (função recursiva)
    printf("\n=== Rainha - Nivel Mestre ===\n");
    moverRainha(CASAS_RAINHA);

    // Cavalo: 1x em L para cima à direita (2 cima + 1 direita)
    // Loop com variáveis múltiplas na inicialização, condições múltiplas,
    // continue (mantém o loop enquanto há casas verticais) e
    // break (encerra após concluir a casa horizontal).
    printf("\n=== Cavalo - Nivel Mestre ===\n");
    for (int vertical = 2, horizontal = 1; vertical > 0 || horizontal > 0; ) {
        if (vertical > 0) {
            printf("Cima\n");
            vertical--;
            continue; // ainda há casas verticais, reinicia o loop
        }
        if (horizontal > 0) {
            printf("Direita\n");
            horizontal--;
            break; // movimento em L concluído, encerra o loop
        }
    }

    return 0;
}
