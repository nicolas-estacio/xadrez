#include <stdio.h>
#include <locale.h>


// Função recursiva para simular o movimento da Torre (5 casas para a direita)
void moveTorre(int casas, int atual) {
    // Caso base: se todas as casas foram percorridas, retorna
    if (atual > casas) return;
    
    // Imprime a direção do movimento
    printf("Direita\n");
    
    // Chamada recursiva para a próxima casa
    moveTorre(casas, atual + 1);
}

// Função recursiva para simular o movimento do Bispo (5 casas na diagonal para cima e à direita)
void moveBispoRecursivo(int casas, int atual) {
    // Caso base: se todas as casas foram percorridas, retorna
    if (atual > casas) return;
    
    // Imprime a direção do movimento diagonal
    printf("Cima, Direita\n");
    
    // Chamada recursiva para a próxima casa
    moveBispoRecursivo(casas, atual + 1);
}

// Função com loops aninhados para simular o movimento do Bispo
void moveBispoAninhado(int casas) {
    // Loop externo controla o movimento vertical (cima)
    for (int i = 1; i <= casas; i++) {
        // Loop interno controla o movimento horizontal (direita)
        for (int j = 1; j <= 1; j++) { // Apenas uma iteração por casa, pois é diagonal
            printf("Cima, Direita\n");
        }
    }
}

// Função recursiva para simular o movimento da Rainha (8 casas para a esquerda)
void moveRainha(int casas, int atual) {
    // Caso base: se todas as casas foram percorridas, retorna
    if (atual > casas) return;
    
    // Imprime a direção do movimento
    printf("Esquerda\n");
    
    // Chamada recursiva para a próxima casa
    moveRainha(casas, atual + 1);
}

// Função com loops aninhados complexos para simular o movimento do Cavalo (L: 2 casas para cima, 1 para a direita)
void moveCavalo(int repeticoes) {
    // Loop externo para controlar o número de movimentos em L
    for (int i = 1; i <= repeticoes; i++) {
        int etapa = 1; // Controla as etapas do movimento em L (2 cima, 1 direita)
        
        // Loop interno para simular as etapas do movimento em L
        for (int j = 1; j <= 3; j++) {
            // Pula etapas inválidas (controle com continue)
            if (j > 3) {
                continue;
            }
            
            // Primeiras duas etapas: mover para cima
            if (etapa <= 2) {
                printf("Cima\n");
                etapa++;
            }
            // Terceira etapa: mover para a direita
            else if (etapa == 3) {
                printf("Direita\n");
                etapa++;
                break; // Interrompe o loop interno após completar o movimento em L
            }
        }
        
        // Adiciona linha em branco após cada movimento completo do Cavalo
        printf("\n");
    }
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    // Simulação do movimento da Torre (5 casas para a direita, recursivo)
    printf("Movimento da Torre:\n");
    moveTorre(5, 1);
    printf("\n"); // Linha em branco para separar peças

    // Simulação do movimento do Bispo (5 casas na diagonal, recursivo)
    printf("Movimento do Bispo (Recursivo):\n");
    moveBispoRecursivo(5, 1);
    printf("\n"); // Linha em branco para separar peças

    // Simulação do movimento do Bispo (5 casas na diagonal, com loops aninhados)
    printf("Movimento do Bispo (Aninhado):\n");
    moveBispoAninhado(5);
    printf("\n"); // Linha em branco para separar peças

    // Simulação do movimento da Rainha (8 casas para a esquerda, recursivo)
    printf("Movimento da Rainha:\n");
    moveRainha(8, 1);
    printf("\n"); // Linha em branco para separar peças

    // Simulação do movimento do Cavalo (2 movimentos em L: 2 cima, 1 direita)
    printf("Movimento do Cavalo:\n");
    moveCavalo(2); // Dois movimentos em L

    return 0;
}
