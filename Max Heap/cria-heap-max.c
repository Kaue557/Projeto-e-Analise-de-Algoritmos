/*
Escreva em C uma função cria-heap-max() que recebe um vetor v de inteiros e seu tamanho n e cria o max-heap. 

Seu programa deve imprimir o max-heap final.
*/
#include <stdio.h>
#include <stdbool.h>


void afunda(int vetor[], int i, int  n){ // void?
    int aux = 0; // var auxiliar p/ troca

    if(vetor[i] < vetor[2*i]){
        aux = vetor[i];
        vetor[i] = vetor[2*i];
        vetor[2*i] = aux;

    }

    int posPai = i/2;
    int posFilhoEsq = 2*i;
    int posFilhoDir = (2*i) + 1;


}

void criaHeapMax(int vetor[], int n){
    for (int i = n/2; i >= 1; i--){
        afunda(vetor, i, n);
    }
}

int main(){
    int vetor[] = {0, 12, 11, 7, 15, 21, 22, 13, 9, 1, 3, 8, 3}; //ignora o indice 0 para manter a logica das contas
    int tamanho = sizeof(vetor) / sizeof(int); // tamanho real do vetor

    // impressao do vetor ordenado 
    printf("Vetor Max Heap: \n[ ");
    for(int j = 1; j < tamanho; j++){
        printf("%d", vetor[j]);
    }
    printf(" ]");
    

    return 0;
}
