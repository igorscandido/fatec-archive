#include <stdio.h>
#include <math.h>

double calcularMedia(double v[], int n);
double calcularDesvioPadrao(double v[], int n);

int main() {
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    double v[n];
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &v[i]);
    }

    double desvioPadrao = calcularDesvioPadrao(v, n);
    printf("O desvio padrão do vetor é: %.2f\n", desvioPadrao);

    return 0;
}

double calcularMedia(double v[], int n) {
    double soma = 0.0;
    for (int i = 0; i < n; i++) {
        soma += v[i];
    }
    return soma / n;
}

double calcularDesvioPadrao(double v[], int n) {
    double media = calcularMedia(v, n);
    double somaDesvios = 0.0;

    for (int i = 0; i < n; i++) {
        somaDesvios += pow(v[i] - media, 2);
    }

    double variancia = somaDesvios / n;
    return sqrt(variancia);
}
