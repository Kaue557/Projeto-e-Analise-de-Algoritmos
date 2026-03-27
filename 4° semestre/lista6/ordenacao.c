/*
1. Escreva um algoritmo utilizando a estratégia Backtracking que ordena um vetor de N
elementos inteiros. (Um tanto ridículo, mas pode ser um bom exercício). O seu algoritmo
funciona para números repetidos ?
*/

#include <stdio.h>
#include <stdlib.h>


// DEVE TA ERRADO
void ordena(int vet[], int n){
    if(n == 1){
        printf("%d ", vet[0]);
    }
    else{
        for(int i = 0; i < n; i++){
            troca(&vet[i], &vet[n-1]);
            ordena(vet, n-1);
            troca(&vet[i], &vet[n-1]);
        }
    }
}

void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int vet[] = {5, 2, 8, 1, 9};

    return 0;
}