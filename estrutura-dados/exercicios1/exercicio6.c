#include <stdio.h>

#define MAX_PEDIDOS 10

int main() {
    int codigo[MAX_PEDIDOS];
    float valor_unitario[MAX_PEDIDOS];
    int quantidade[MAX_PEDIDOS];
    float total_item[MAX_PEDIDOS];

    for (int i = 0; i < MAX_PEDIDOS; i++) {
        printf("Informe os dados do produto %d:\n", i + 1);
        printf("Código do produto: ");
        scanf("%d", &codigo[i]);
        printf("Valor unitário: ");
        scanf("%f", &valor_unitario[i]);
        printf("Quantidade vendida: ");
        scanf("%d", &quantidade[i]);

        total_item[i] = valor_unitario[i] * quantidade[i];
    }

    printf("\nListagem de Produtos:\n");
    printf("CODIGO   V. UNIT   QTD   TOTAL ITEM\n");
    for (int i = 0; i < MAX_PEDIDOS; i++) {
        printf("%-8d %-8.2f %-5d %-10.2f\n", codigo[i], valor_unitario[i], quantidade[i], total_item[i]);
    }

    int quantidade_total = 0;
    float valor_total_vendido = 0.0;

    for (int i = 0; i < MAX_PEDIDOS; i++) {
        quantidade_total += quantidade[i];
        valor_total_vendido += total_item[i];
    }

    float media_itens_por_venda = (float)quantidade_total / MAX_PEDIDOS;
    float valor_unitario_medio = valor_total_vendido / quantidade_total;
    float media_valor_total_por_item = valor_total_vendido / MAX_PEDIDOS;

    printf("\nResultados:\n");
    printf("Quantidade total de itens vendidos: %d\n", quantidade_total);
    printf("Valor total vendido: %.2f\n", valor_total_vendido);
    printf("Quantidade média de itens por venda: %.2f\n", media_itens_por_venda);
    printf("Valor unitário médio: %.2f\n", valor_unitario_medio);
    printf("Média do valor total por item: %.2f\n", media_valor_total_por_item);

    int codigo_consulta;
    printf("\nInforme um código para consulta de item vendido: ");
    scanf("%d", &codigo_consulta);

    int encontrado = 0;
    for (int i = 0; i < MAX_PEDIDOS; i++) {
        if (codigo[i] == codigo_consulta) {
            printf("Informações do produto:\n");
            printf("Código: %d\n", codigo[i]);
            printf("Valor unitário: %.2f\n", valor_unitario[i]);
            printf("Quantidade: %d\n", quantidade[i]);
            printf("Total item: %.2f\n", total_item[i]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Código não encontrado.\n");
    }

    return 0;
}
