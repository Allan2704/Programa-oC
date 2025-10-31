#include <stdio.h>

struct Carta {
    char estado[3];
    char codigo[5];
    char nomeCidade[30];
    int populacao;
    float area;
    float pib;
};

int main() {
    struct Carta c1 = {"SP", "A01", "São Paulo", 12300000, 1521.11, 699.28};
    struct Carta c2 = {"RJ", "A02", "Rio de Janeiro", 6775561, 1182.30, 364.62};

    float densidade1, densidade2, pibPerCapita1, pibPerCapita2;

    // Cálculos carta 1
    densidade1 = c1.populacao / c1.area;
    pibPerCapita1 = (c1.pib * 1000000000) / c1.populacao;

    // Cálculos carta 2
    densidade2 = c2.populacao / c2.area;
    pibPerCapita2 = (c2.pib * 1000000000) / c2.populacao;

    printf("\n===== CARTA 1 =====\n");
    printf("Estado: %s\n", c1.estado);
    printf("Código: %s\n", c1.codigo);
    printf("Cidade: %s\n", c1.nomeCidade);
    printf("População: %d\n", c1.populacao);
    printf("Área: %.2f km²\n", c1.area);
    printf("PIB: %.2f bilhões\n", c1.pib);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita1);

    printf("\n===== CARTA 2 =====\n");
    printf("Estado: %s\n", c2.estado);
    printf("Código: %s\n", c2.codigo);
    printf("Cidade: %s\n", c2.nomeCidade);
    printf("População: %d\n", c2.populacao);
    printf("Área: %.2f km²\n", c2.area);
    printf("PIB: %.2f bilhões\n", c2.pib);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita2);

    return 0;
}
