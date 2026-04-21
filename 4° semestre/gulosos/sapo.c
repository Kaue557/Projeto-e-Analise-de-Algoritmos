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
int salto_sapo(int n, int p[], int delta, int u[]){
    int local_pedra = p[0];
    int k = 1;
    u[0] = p[0];

    for(int i = 1; i < n; i++){
        if(p[i] - local_pedra > delta){ // se a diferenca for maior
            local_pedra = p[i-1];
            u[k] = p[i-1];
            k++;
        }
    }
    if(u[k-1] != p[n-1]){
        u[k] = p[n-1];
        k++;
    }
    
    return k;
}


int main(){
    int n = 5;
    int p[] = {0, 2, 4, 5, 6, 7};
    int u[MAX];
    int delta = 2;

    int k = salto_sapo(n, p, delta, u);

    printf("Pedras escolhidas:\n");
    for(int i = 0; i < k; i++){
        printf("%d ", u[i]);
    }
    printf("\n");

    printf("Quantidade de saltos: %d\n", k);

    return 0;
}