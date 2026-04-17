#include <stdio.h>

#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n;
    int tri[MAX][MAX];

    // número de linhas
    scanf("%d", &n);

    // leitura da pirâmide
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &tri[i][j]);
        }
    }

    // programação dinâmica (de baixo para cima)
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            tri[i][j] += max(tri[i+1][j], tri[i+1][j+1]);
        }
    }

    // resultado final (topo)
    printf("Maior soma: %d\n", tri[0][0]);

    return 0;
}