#include <stdio.h>

void inverter(int vet[], int inicio, int fim){
    if(inicio >= fim) return;

    // troca
    int temp = vet[inicio];
    vet[inicio] = vet[fim];
    vet[fim] = temp;

    return inverter(vet, inicio + 1, fim - 1);
}

int main(){
    int vet[] = {1, 5, 2, 7, 6, 4};
    int n = sizeof(vet) / sizeof(vet[0]);

    printf("Vetor original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }

    inverter(vet, 0, n - 1);

    printf("\n\nVetor invertido:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }

    printf("\n");

    return 0;
}