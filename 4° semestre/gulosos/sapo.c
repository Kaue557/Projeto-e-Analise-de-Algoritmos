#include <stdio.h>
#define MAX 1000

/*
salto sapo(p, n, delta)
1 u ← {p[1]}
2 ultima pos ← p[1]
3 para i = 2 até n faça
4   se p[i] − ultima pos > delta então
5       ultima pos ← p[i − 1]
6       u ← u ∪ p[i − 1]
7 u ← u ∪ p[n]
8 retorne u
*/

/*
n -> num. de pedras
p -> pedra e posicao (p1, p2, ..., pn)
delta -> diferenca permitida
*/
int salto_sapo(int n, int p[], float delta, int u[], int tamU){
    int u[MAX] = {p[0]};
    int ultima_pos = p[0];
    int k = 0;

    for(int i = 1; i < n; i++){
        if(p[i] - ultima_pos > delta){ // se a diferenca for maior
            ultima_pos = p[i-1];
            u[k] = p[k-1];
            k++;
        }
    }
    return k;

}


int main(){



    return 0;
}