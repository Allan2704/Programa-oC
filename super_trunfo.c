#include <stdio.h>

struct Carta {
    char pais[20];
    int populacao;
    float area;
    float pib;
    float densidade;
    float pibPerCapita;
};

void mostrarMenuAtributos(int opcaoEscolhida) {
    printf("\nEscolha um atributo:\n");

    if(opcaoEscolhida != 1) printf("1 - População\n");
    if(opcaoEscolhida != 2) printf("2 - Área\n");
    if(opcaoEscolhida != 3) printf("3 - PIB\n");
    if(opcaoEscolhida != 4) printf("4 - Densidade Demográfica (MENOR vence)\n");
    if(opcaoEscolhida != 5) printf("5 - PIB per Capita\n");

    printf("Escolha: ");
}

float obterValor(struct Carta c, int opcao) {
    switch(opcao) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.densidade; // Menor vence
        case 5: return c.pibPerCapita;
        default: return 0;
    }
}

int main() {
    // Duas cartas pré-definidas
    struct Carta c1 = {"Brasil", 214000000, 8516000.00, 1.90, 214000000 / 8516000.00, (1.90 * 1000000000000) / 214000000};
    struct Carta c2 = {"Argentina", 46000000, 2780000.00, 0.49, 46000000 / 2780000.00, (0.49 * 1000000000000) / 46000000};

    int atributo1, atributo2;

    printf("=== SUPER TRUNFO - Comparação com dois atributos ===\n");
    printf("\nCartas:\n1) %s\n2) %s\n", c1.pais, c2.pais);

    // Escolha do primeiro atributo
    mostrarMenuAtributos(0);
    scanf("%d", &atributo1);

    if (atributo1 < 1 || atributo1 > 5) {
        printf("Opcao invalida! Encerrando.\n");
        return 0;
    }

    // Escolha do segundo atributo (não pode repetir)
    mostrarMenuAtributos(atributo1);
    scanf("%d", &atributo2);

    if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("Opcao invalida! Encerrando.\n");
        return 0;
    }

    // Obter valores
    float v1a = obterValor(c1, atributo1);
    float v2a = obterValor(c2, atributo1);

    float v1b = obterValor(c1, atributo2);
    float v2b = obterValor(c2, atributo2);

    // Comparar cada atributo
    int pontosC1 = 0, pontosC2 = 0;

    // Regra especial: Densidade -> MENOR vence (atributo 4)
    if (atributo1 == 4)
        (v1a < v2a) ? pontosC1++ : (v2a < v1a) ? pontosC2++ : 0;
    else
        (v1a > v2a) ? pontosC1++ : (v2a > v1a) ? pontosC2++ : 0;

    if (atributo2 == 4)
        (v1b < v2b) ? pontosC1++ : (v2b < v1b) ? pontosC2++ : 0;
    else
        (v1b > v2b) ? pontosC1++ : (v2b > v1b) ? pontosC2++ : 0;

    // Soma final
    float somaC1 = v1a + v1b;
    float somaC2 = v2a + v2b;

    printf("\n=== Resultado da Comparação ===\n");
    printf("%s -> %.2f + %.2f = %.2f\n", c1.pais, v1a, v1b, somaC1);
    printf("%s -> %.2f + %.2f = %.2f\n", c2.pais, v2a, v2b, somaC2);

    if (somaC1 > somaC2)
        printf("\n🏆 %s venceu!\n", c1.pais);
    else if (somaC2 > somaC1)
        printf("\n🏆 %s venceu!\n", c2.pais);
    else
        printf("\n⚖️ Empate!\n");

    return 0;
}

