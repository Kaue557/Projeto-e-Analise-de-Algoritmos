#include <stdio.h>

int potencia(int x, int n){
    if(n == 0) return 1;

    else{
        return x * potencia(x, n - 1);
    }
}

int main(){
    int res = potencia(5, 3);

    printf("resposta: %d\n", res);
}