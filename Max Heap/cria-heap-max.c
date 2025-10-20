/*
Escreva em C uma função cria-heap-max() que recebe um vetor v de inteiros e seu tamanho n e cria o max-heap. 

Seu programa deve imprimir o max-heap final.
*/
#include <stdio.h>
#include <stdbool.h>

int posPai(int i){ // precisa ser funcao?
    return i/2;
}

int posFilhoEsq(int i){ // precisa ser funcao?
    return 2*i;
}

int posFilhoDir(int i){ // precisa ser funcao?
    return (2*i) + 1;
}

void criaHeapMax(int vetor, int n){ // void?

    if(posFilhoDir(2) > posFilhoEsq()) // errado*
    for(int i = 1; i < n; i++){ // 'n'? ou sizeof blablabla?

    }

}

int main(){
    int vetor = {12, 11, 7, 15, 21, 22, 13, 9, 1, 3, 8, 3};
    int tamanho = 0;

    return 0;
}
