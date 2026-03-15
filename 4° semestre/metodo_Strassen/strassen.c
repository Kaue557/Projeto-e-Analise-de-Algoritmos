#include <stdio.h>

#define MAX 64

void soma(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j] = A[i][j] + B[i][j];
}

void sub(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j] = A[i][j] - B[i][j];
}

// separa a matriz em quadrantes
void dividir(int P[MAX][MAX], int C[MAX][MAX], int iB, int jB, int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j] = P[i+iB][j+jB];
}

// funcao para anexar à matriz P a matriz C - iB e jB indicam onde comecam a submatriz
void juntar(int P[MAX][MAX], int C[MAX][MAX], int iB, int jB, int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            P[i+iB][j+jB] = C[i][j];
}

void strassen(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n){

    // caso base
    if(n == 1){
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n/2;

    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX], d[MAX][MAX];
    int e[MAX][MAX], f[MAX][MAX], g[MAX][MAX], h[MAX][MAX];

    dividir(A,a,0,0,k);
    dividir(A,b,0,k,k);
    dividir(A,c,k,0,k);
    dividir(A,d,k,k,k);

    dividir(B,e,0,0,k);
    dividir(B,f,0,k,k);
    dividir(B,g,k,0,k);
    dividir(B,h,k,k,k);

    int P1[MAX][MAX],P2[MAX][MAX],P3[MAX][MAX],P4[MAX][MAX];
    int P5[MAX][MAX],P6[MAX][MAX],P7[MAX][MAX];

    int T1[MAX][MAX],T2[MAX][MAX];

    // contas de P1 a P7
    sub(f,h,T1,k);
    strassen(a,T1,P1,k);

    soma(a,b,T1,k);
    strassen(T1,h,P2,k);

    soma(c,d,T1,k);
    strassen(T1,e,P3,k);

    sub(g,e,T1,k);
    strassen(d,T1,P4,k);

    soma(a,d,T1,k);
    soma(e,h,T2,k);
    strassen(T1,T2,P5,k);

    sub(b,d,T1,k);
    soma(g,h,T2,k);
    strassen(T1,T2,P6,k);

    sub(a,c,T1,k);
    soma(e,f,T2,k);
    strassen(T1,T2,P7,k);

    int r[MAX][MAX], s[MAX][MAX], t[MAX][MAX], u[MAX][MAX];

    soma(P5,P4,T1,k);
    sub(T1,P2,T2,k);
    soma(T2,P6,r,k);

    soma(P1,P2,s,k);

    soma(P3,P4,t,k);

    soma(P5,P1,T1,k);
    sub(T1,P3,T2,k);
    sub(T2,P7,u,k);

    juntar(C,r,0,0,k);
    juntar(C,s,0,k,k);
    juntar(C,t,k,0,k);
    juntar(C,u,k,k,k);
}


int main(){

    int n = 2;

    int A[MAX][MAX] = {
        {1,2},
        {3,4}
    };

    int B[MAX][MAX] = {
        {5,6},
        {7,8}
    };

    int C[MAX][MAX] = {0};

    strassen(A,B,C,n);

    printf("Matriz C resultante:\n");

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d ",C[i][j]);
        printf("\n");
    }
    printf("\n");

    return 0;
}