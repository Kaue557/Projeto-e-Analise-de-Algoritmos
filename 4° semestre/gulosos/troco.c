#include <stdio.h>
#define MAX 100

// ordena em ordem decrescente (bubble sort simples)
void ordenarDecrescente(int v[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (v[j] < v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

int troco(int conjunto[], int tam, int valor, int S[], int *tamS){
    ordenarDecrescente(conjunto, tam);

    int soma = 0;
    int posicao = 0;

    for (int i = 0; i < tam; i++) {
        while (soma + conjunto[i] <= valor) {
            soma += conjunto[i];
            S[posicao] = conjunto[i];
            posicao++;
        }
    }

    *tamS = posicao;

    if(soma == valor){ //se tiver chegado no valor do troco
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int conjunto[] = {1, 2, 5};
    int tam = 3;
    int valor = 12;

    int S[MAX];
    int tamS = 0;
    
    if (troco(conjunto, tam, valor, S, &tamS)) {
        printf("Moedas usadas: ");
        for (int i = 0; i < tamS; i++) {
            printf("%d ", S[i]);
        }
        printf("\n");
    } else {
        printf("Solucao nao encontrada\n");
    }

    return 0;
}