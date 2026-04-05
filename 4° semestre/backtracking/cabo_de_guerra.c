#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 20

int arr[MAX];
int melhor_subconjunto[MAX];
int atual[MAX];

int n, k;
int total = 0;
int melhor_diff = INT_MAX;

// função recursiva
void backtracking(int i, int escolhidos, int soma_atual) {

    // poda: não há elementos suficientes restantes
    if (escolhidos + (n - i) < k)
        return;

    // caso base
    if (i == n) {
        if (escolhidos == k) {
            int diff = abs(total - 2 * soma_atual);

            if (diff < melhor_diff) {
                melhor_diff = diff;

                for (int j = 0; j < n; j++)
                    melhor_subconjunto[j] = atual[j];
            }
        }
        return;
    }

    // escolha: incluir arr[i]
    atual[i] = 1;
    backtracking(i + 1, escolhidos + 1, soma_atual + arr[i]);

    // não escolher
    atual[i] = 0;
    backtracking(i + 1, escolhidos, soma_atual);
}

// função principal
void cabo_de_guerra() {

    total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];

    // define tamanho do subconjunto
    k = n / 2;

    backtracking(0, 0, 0);

    // imprime resultado
    printf("Subconjunto 1:\n");
    for (int i = 0; i < n; i++) {
        if (melhor_subconjunto[i])
            printf("%d ", arr[i]);
    }

    printf("\nSubconjunto 2:\n");
    for (int i = 0; i < n; i++) {
        if (!melhor_subconjunto[i])
            printf("%d ", arr[i]);
    }

    printf("\nDiferença mínima: %d\n", melhor_diff);
}

// main para teste
int main() {

    int exemplo[] = {3, 4, 5, -3, 100, 1, 89, 54, 23, 20};
    n = sizeof(exemplo) / sizeof(exemplo[0]);

    for (int i = 0; i < n; i++)
        arr[i] = exemplo[i];

    cabo_de_guerra();

    return 0;
}