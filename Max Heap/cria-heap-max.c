/*
Escreva em C uma função cria-heap-max() que recebe um vetor v de inteiros e seu tamanho n e cria o max-heap. 

Seu programa deve imprimir o max-heap final.
*/
#include <stdio.h>
#include <stdbool.h>

void afunda(int vetor, int i, int  n){ // void?
    int i = 1; // comecando em 1 para facilitar o manejo

    int posPai = i/2;
    int posFilhoEsq = 2*i;
    int posFilhoDir = (2*i) + 1;


}

void criaHeapMax(int vetor, int n){ // void?

    for(int i = 1; i < n; i++){ // 'n'? ou sizeof blablabla?

    }

}

int main(){
    int vetor = {0, 12, 11, 7, 15, 21, 22, 13, 9, 1, 3, 8, 3}; //ignora o indice 0 para manter a logica das contas
    int tamanho = sizeof(vetor) / sizeof(int); // tamanho real do vetor

    return 0;
}
