#include <stdio.h>

#define MAX 1000

void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ordenar(int A[], int n){
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(A[i] > A[j])
                troca(&A[i], &A[j]);
}

int selecao(int A[], int n, int k);

// retorna a mediana
int mediana5(int A[], int n){
    ordenar(A,n);
    return A[n/2];
}

int selecao(int A[], int n, int k){

    // caso base
    if(n < 15){
        ordenar(A,n);
        return A[k-1];
    }

    int M[MAX];
    int mCount = 0;

    // dividir em grupos de 5
    for(int i=0;i<n;i+=5){
        int grupo[5];
        int tam = 0;

        for(int j=0;j<5 && i+j<n;j++){
            grupo[tam++] = A[i+j];
        }

        M[mCount++] = mediana5(grupo,tam);
    }

    // mediana das medianas
    int m = selecao(M, mCount, (mCount+1)/2);

    int L1[MAX], L2[MAX], L3[MAX];
    int n1=0,n2=0,n3=0;

    // particionamento de L1, L2 e L3
    for(int i=0;i<n;i++){
        if(A[i] < m)
            L1[n1++] = A[i];
        else if(A[i] > m)
            L3[n3++] = A[i];
        else
            L2[n2++] = A[i];
    }

    // casos de k estar entre os menores, maiores que m ou igual ao pivo
    if(k <= n1)
        return selecao(L1, n1, k);

    else if(k <= n1 + n2)
        return m;

    else
        return selecao(L3, n3, k - n1 - n2);
}

int main(){

    int A[] = {10,8,15,9,7,20,6,1,4,19,12,11,2,5,3,18,13,14,16,17};
    int n = 20;
    int k = 5;

    int resultado = selecao(A,n,k);

    printf("%d-esimo menor = %d\n", k, resultado);

    return 0;
}