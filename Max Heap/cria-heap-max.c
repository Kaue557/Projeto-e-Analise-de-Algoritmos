/*
Escreva em C uma função cria-heap-max() que recebe um vetor v de inteiros e seu tamanho n e cria o max-heap. 

Seu programa deve imprimir o max-heap final.
*/
#include <stdio.h>
#include <stdbool.h>


void afunda(int vetor[], int i, int  n){ // void?
    int maior = i;
    int esq = 2 * i;
    int dir = (2*i) + 1;
    int aux = 0; // var auxiliar p/ troca

    if (esq <= n && vetor[esq] > vetor[maior]){ // verifica se o maior eh o filho esquerdo
        maior = esq;
    }

    if (dir <= n && vetor[dir] > vetor[maior]){ // verifica se o maior eh o filho direito
        maior = dir;
    }

    if(maior != i){ // se um dos filhos for maior que o pai, troca 
        aux = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = aux;
        afunda(vetor, maior, n); // chama a funcao de novo ate que o maior seja o "do topo", recursao 
    }

}

void criaHeapMax(int vetor[], int n){
    for (int i = n/2; i >= 1; i--){
        afunda(vetor, i, n);
    }
}

int main(){
    int vetor[] = {0, 12, 11, 7, 15, 21, 22, 13, 9, 1, 3, 8, 3}; //ignora o indice 0 para manter a logica das contas
    int tamanho = sizeof(vetor) / sizeof(int) - 1; // tamanho real do vetor

    criaHeapMax(vetor, tamanho); // chamada da funcao

    // impressao do vetor ordenado 
    printf("Vetor Max Heap: \n[ ");
    for(int j = 1; j <= tamanho; j++){
        printf("%d ", vetor[j]);
    }
    printf("]\n");
    
    return 0;
}
