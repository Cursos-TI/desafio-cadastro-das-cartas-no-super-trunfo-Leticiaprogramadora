#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta
struct Carta {
    char nomeCidade[100];
    float densidade;
    float pibPerCapita;
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float superPoder; // novo atributo
};

// Função para calcular o Super Poder da carta
float calcularSuperPoder(struct Carta c) {
    return (float)c.populacao + c.area + c.pib + c.pontosTuristicos + c.pibPerCapita + (1 / c.densidade);
}

int main() {
    struct Carta carta1 = {"Curitiba", 4200.00, 48200.00, 1963726, 430.9, 94.6, 35};
    struct Carta carta2 = {"Brusque", 780.00, 53000.00, 137689, 176.5, 7.3, 15};

    // Calcula e armazena o Super Poder das cartas
    carta1.superPoder = calcularSuperPoder(carta1);
    carta2.superPoder = calcularSuperPoder(carta2);

    int escolha1, escolha2;
    float valor1Carta1, valor1Carta2;
    float valor2Carta1, valor2Carta2;
    float soma1, soma2;

    // Menu do primeiro atributo
    printf("Escolha o primeiro atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (vence menor)\n");
    printf("6 - PIB per Capita\n");
    printf("Opção: ");
    scanf("%d", &escolha1);

    // Menu do segundo atributo
    printf("\nEscolha o segundo atributo para comparação (diferente do primeiro):\n");
    switch (escolha1) {
        case 1: printf("2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n6 - PIB per Capita\n"); break;
        case 2: printf("1 - População\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n6 - PIB per Capita\n"); break;
        case 3: printf("1 - População\n2 - Área\n4 - Pontos Turísticos\n5 - Densidade Populacional\n6 - PIB per Capita\n"); break;
        case 4: printf("1 - População\n2 - Área\n3 - PIB\n5 - Densidade Populacional\n6 - PIB per Capita\n"); break;
        case 5: printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n6 - PIB per Capita\n"); break;
        case 6: printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n"); break;
        default: printf("Opção inválida.\n"); return 1;
    }

    printf("Opção: ");
    scanf("%d", &escolha2);

    if (escolha1 == escolha2) {
        printf("\nVocê não pode escolher o mesmo atributo duas vezes.\n");
        return 1;
    }

    // Leitura dos valores dos atributos escolhidos
    switch (escolha1) {
        case 1: valor1Carta1 = carta1.populacao; valor1Carta2 = carta2.populacao; break;
        case 2: valor1Carta1 = carta1.area; valor1Carta2 = carta2.area; break;
        case 3: valor1Carta1 = carta1.pib; valor1Carta2 = carta2.pib; break;
        case 4: valor1Carta1 = carta1.pontosTuristicos; valor1Carta2 = carta2.pontosTuristicos; break;
        case 5: valor1Carta1 = carta1.densidade; valor1Carta2 = carta2.densidade; break;
        case 6: valor1Carta1 = carta1.pibPerCapita; valor1Carta2 = carta2.pibPerCapita; break;
        default: printf("Atributo inválido.\n"); return 1;
    }

    switch (escolha2) {
        case 1: valor2Carta1 = carta1.populacao; valor2Carta2 = carta2.populacao; break;
        case 2: valor2Carta1 = carta1.area; valor2Carta2 = carta2.area; break;
        case 3: valor2Carta1 = carta1.pib; valor2Carta2 = carta2.pib; break;
        case 4: valor2Carta1 = carta1.pontosTuristicos; valor2Carta2 = carta2.pontosTuristicos; break;
        case 5: valor2Carta1 = carta1.densidade; valor2Carta2 = carta2.densidade; break;
        case 6: valor2Carta1 = carta1.pibPerCapita; valor2Carta2 = carta2.pibPerCapita; break;
        default: printf("Atributo inválido.\n"); return 1;
    }

    float valor1 = (escolha1 == 5) ? -valor1Carta1 : valor1Carta1;
    float valor2 = (escolha1 == 5) ? -valor1Carta2 : valor1Carta2;
    float valor3 = (escolha2 == 5) ? -valor2Carta1 : valor2Carta1;
    float valor4 = (escolha2 == 5) ? -valor2Carta2 : valor2Carta2;

    soma1 = valor1 + valor3;
    soma2 = valor2 + valor4;

    // Exibição dos resultados
    printf("\n--- Resultado da Rodada ---\n");
    printf("Carta 1 - %s\n", carta1.nomeCidade);
    printf("Carta 2 - %s\n\n", carta2.nomeCidade);

    printf("Atributo 1 (opção %d): Carta 1 = %.2f | Carta 2 = %.2f\n", escolha1, valor1Carta1, valor1Carta2);
    printf("Atributo 2 (opção %d): Carta 1 = %.2f | Carta 2 = %.2f\n", escolha2, valor2Carta1, valor2Carta2);

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", carta1.nomeCidade, soma1);
    printf("%s: %.2f\n", carta2.nomeCidade, soma2);

    printf("\nResultado: ");
    printf((soma1 > soma2) ? "%s venceu!\n" :
           (soma2 > soma1) ? "%s venceu!\n" :
           "Empate!\n", (soma1 > soma2) ? carta1.nomeCidade : carta2.nomeCidade);

    // Exibir Super Poder
    printf("\n--- Super Poder ---\n");
    printf("%s: %.2f\n", carta1.nomeCidade, carta1.superPoder);
    printf("%s: %.2f\n", carta2.nomeCidade, carta2.superPoder);

    printf("Resultado do Super Poder: ");
    if (carta1.superPoder > carta2.superPoder)
        printf("%s venceu!\n", carta1.nomeCidade);
    else if (carta2.superPoder > carta1.superPoder)
        printf("%s venceu!\n", carta2.nomeCidade);
    else
        printf("Empate!\n");

    return 0;
}
