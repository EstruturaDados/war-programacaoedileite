# 🗺️ Desafio WAR Estruturado – Conquista de Territórios

Bem-vindo ao **Desafio WAR Estruturado!** Inspirado no famoso jogo de estratégia, este desafio convida você a programar diferentes versões do jogo WAR, evoluindo seus conhecimentos em **C** à medida que avança pelos níveis **Novato**, **Aventureiro** e **Mestre**.

A empresa **MateCheck** contratou você para criar uma versão estruturada do WAR. Cada nível propõe novas funcionalidades, conceitos e desafios de programação. **Você escolhe por onde começar!**

---

## 🧩 Nível Novato: Cadastro Inicial dos Territórios

### 🎯 Objetivo

- Criar uma `struct` chamada `Territorio`.
- Usar um **vetor estático de 5 elementos** para armazenar os territórios.
- Cadastrar os dados de cada território: **Nome**, **Cor do Exército**, e **Número de Tropas**.
- Exibir o estado atual do mapa.

### ⚙️ Funcionalidades

- Leitura de dados pelo terminal (`fgets` e `scanf`)
- Impressão organizada dos dados de todos os territórios

### 💡 Conceitos abordados

- `struct`
- Vetor estático
- Entrada/saída com `scanf`, `fgets`, e `printf`

### 📥 Entrada

O usuário digita o nome do território, a cor do exército dominante e o número de tropas para **cada um dos 5 territórios**.

### 📤 Saída



## 🧗‍♂️ Nível Aventureiro: Batalhas Estratégicas

### 🎯 Objetivo

- Substituir o vetor estático por **alocação dinâmica com `calloc`**
- Criar uma função para **simular ataques entre dois territórios**
- Utilizar números aleatórios para representar dados de batalha

### 🆕 Novidades em relação ao Nível Novato

- Alocação dinâmica de memória com `calloc`
- Uso de **ponteiros**
- Laço interativo para o jogador escolher **territórios para atacar e defender**
- Simulação de dados de ataque e defesa com `rand()`

### ⚙️ Funcionalidades

- Cadastro dos territórios (como no Nível Novato)
- Fase de ataque com:
  - Escolha de atacante e defensor
  - Dados de ataque/defesa
  - Lógica:
    - Se atacante vence → defensor perde 1 tropa
    - Se defensor perde todas → território é conquistado
    - Empates favorecem o atacante

### 💡 Conceitos abordados

- Ponteiros
- `calloc` / `free`
- Aleatoriedade com `rand()` / `srand()`
- Funções para modularização

### 📥 Entrada

- Território **atacante** (1 a 5)
- Território **defensor** (1 a 5)

### 📤 Saída

Exibição do resultado da batalha, dados sorteados e mudanças no mapa.



## 🧠 Nível Mestre: Missões e Modularização Total

### 🎯 Objetivo

- Dividir o código em funções bem definidas
- Implementar um **sistema de missões**
- Verificar cumprimento da missão
- Aplicar **boas práticas** (uso de `const`, modularização, etc.)

### 🆕 Diferenças em relação ao Nível Aventureiro

- Modularização total em funções
- Missões aleatórias atribuídas:
  1. Destruir o exército **Verde**
  2. Conquistar **3 territórios**
- Menu interativo com opções

### ⚙️ Funcionalidades

- Inicialização automática dos territórios
- Menu principal com 3 opções:
  1. Atacar
  2. Verificar Missão
  3. Sair
- Verificação de vitória da missão

### 💡 Conceitos abordados

- Modularização
- `const` correctness
- Estruturação em múltiplas funções
- Passagem por referência

### 📥 Entrada

- Ações do jogador via menu:
  - `1` - Atacar
  - `2` - Verificar Missão
  - `0` - Sair
- Escolha de territórios para ataque

### 📤 Saída

- Mapa atualizado
- Resultados das batalhas
- Verificação da missão
- Mensagem de vitória



## 🏁 Conclusão

Com este **Desafio WAR Estruturado**, você praticará fundamentos essenciais da linguagem **C** de forma **divertida e progressiva**.

Cada nível foca em um conjunto de habilidades:

- 🟢 **Novato**: `struct`, vetor, entrada/saída
- 🔵 **Aventureiro**: ponteiros, memória dinâmica, lógica de jogo
- 🟣 **Mestre**: modularização, design limpo, sistema de missões



🚀 **Boa sorte! Avance nos níveis e torne-se um mestre da programação estratégica!**

> Equipe de Ensino – MateCheck

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

    printf(“ ***** SISTEMA DE CADASTRO - JOGO WAR *****\n");
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
