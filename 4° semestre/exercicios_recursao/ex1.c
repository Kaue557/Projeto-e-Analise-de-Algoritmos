#include <stdio.h>

int mult(int a, int b){
    if(b == 1) return a;
    else{
        return mult(a, b-1) + a;
    }
}

int main(){
    int res = mult(3, 5);
    printf("resultado: %d\n", res);
}
