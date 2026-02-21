#include <stdio.h>

int somaImpares(int n){
    if(n == 1) return 1;

    else{
        return (2*n - 1) + somaImpares(n - 1);
    }
}

int main(){
    int res = somaImpares(5);

    printf("resposta: %d\n", res);
}