#include <stdio.h>
double potencia(int x, int n){
    if(n == 0) return 1;

    else{
        return x * potencia(x, n - 1);
    }
}

double fatorial(int n){
    if(n == 0) return 1;

    else{
        return n * fatorial(n - 1);
    }
}

double somatoria(int x, int n){
    if(n == 0) return 1;

    else{
        return (potencia(x, n) / fatorial(n)) + somatoria(x, n - 1);
    }
}

int main(){
    double res = somatoria(2, 3);

    printf("resposta: %.2f\n", res);
}