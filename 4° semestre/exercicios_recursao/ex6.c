#include <stdio.h>

int maior(int v[], int n) {
    if (n == 1)
        return v[0];

    int m = maior(v, n - 1);
    return (v[n - 1] > m) ? v[n - 1] : m;
}

int main(){
    int v[] = {1, 5, 2, 7, 6, 3};
    int n = sizeof(v) / sizeof(v[0]);

    int res = maior(v, n);

    printf("Maior elemento: %d\n", res);


    return 0;
}