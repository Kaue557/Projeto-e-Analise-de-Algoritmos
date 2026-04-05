#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
1. (QUADRADO COM PALITOS DE FÓSFOROS) Dado um vetor de inteiros palitos_de_fosforos ,
onde o palitos_de_fosforos[i] é o tamanho do i-esimo palito de fósforo. Deseja-se usar
todos os palitos de fósforos para fazer um quadrado. Não é permitido quebrar nenhum
palito. Escreva uma função que devolva true se você pode construir um quadrado e falso
caso contrário.
Restrições:
• 1 <= len(palitos_de_fosforos) <= 15
• 1 <= palitos_de_fosforos[i] <= 108
*/

#define MAX 15

int lados[4];

bool backtracking(int palitos[], int n, int i, int alvo) {
    if (i == n) {
        return (lados[0] == alvo &&
                lados[1] == alvo &&
                lados[2] == alvo &&
                lados[3] == alvo);
    }

    for (int j = 0; j < 4; j++) {
        if (lados[j] + palitos[i] <= alvo) {
            lados[j] += palitos[i];

            if (backtracking(palitos, n, i + 1, alvo))
                return true;

            lados[j] -= palitos[i]; // desfaz a escolha
        }
    }

    return false;
}

bool pode_construir_quadrado(int palitos[], int n) {

    int soma = 0;
    for (int i = 0; i < n; i++)
        soma += palitos[i];

    if (soma % 4 != 0)
        return false;

    int alvo = soma / 4; 

    for (int i = 0; i < 4; i++)
        lados[i] = 0;

    return backtracking(palitos, n, 0, alvo);
}

int main() {
    int palitos[] = {1};
    int n = sizeof(palitos)/sizeof(palitos[0]);

    if (pode_construir_quadrado(palitos, n))
        printf("Possivel\n");
    else
        printf("Nao possivel\n");

    return 0;
}