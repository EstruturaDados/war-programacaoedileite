#include <stdio.h>
#include <string.h>

//**** Definição da STRUCT Território ****

struct Territorio {
    char Nome[40];
    char Cor[20];
    int Tropas;
};

//**** Função para limpar BUFFER de Entrada ****

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// **** FUNÇÃO PRINCIPAL ****

int main() {

    struct Territorio Mapa[5]; /* Declaração do VETOR de Territórios com capacidade para 5 territórios */

    int i; // Variável de controle para loop

    printf(" ***** SISTEMA DE CADASTRO - JOGO WARS ***** \n");

    printf(" --- Cadastre 5 territórios para iniciar o jogo:\n\n");

    // *** CADASTRO DOS 5 TERRITÓRIOS ***
    // Laço for para percorrer e preencher todos os territórios
    for (i = 0; i < 5; i++) {
        printf("--- TERRITÓRIO %d ---\n", i + 1);
        
        printf("Nome do território: ");         // Entrada do nome do território
        scanf("%39s", Mapa[i].Nome); // Lê até 39 caracteres para evitar overflow
        limparBuffer(); // Limpa o buffer após scanf

        printf("Cor do exército (Ex: Verde, azul, ...): "); // Entrada da cor do exército
        scanf("%19s", Mapa[i].Cor); // Lê até 19 caracteres
        limparBuffer();

        printf("Quantidade de tropas: "); // Entrada da quantidade de tropas
        scanf("%d", &Mapa[i].Tropas);
        limparBuffer();
        
        printf("\n");
    }

    // --- EXIBIÇÃO DOS DADOS CADASTRADOS ---
    printf(" ***** TERRITÓRIOS CADASTRADOS *****\n");
    
    // Laço for para percorrer e exibir todos os territórios
    for (i = 0; i < 5; i++) {
        printf("Território %d:\n", i + 1);
        printf("  Nome:   %s\n", Mapa[i].Nome);
        printf("  Cor:    %s\n", Mapa[i].Cor);
        printf("  Tropas: %d\n", Mapa[i].Tropas);
        printf("-----------------------------------------------\n");
    }

    printf("Cadastro concluído! Preparando para a batalha...\n");
    printf("****************************************\n");
    
    return 0;
}