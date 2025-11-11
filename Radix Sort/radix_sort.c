#include <stdio.h>

// Encontra o maior valor do vetor para saber quantos digitos o mesmo tem (quantas passadas)
int getMaximo(int arr[], int n){
    int maximo = arr[0];

    for(int i = 1; i < n; i++){
        if(arr[i] > maximo){
            maximo = arr[i];
        }

    return maximo;
    }
}

// Counting sort foi o escolhido (iria usar o bubble, mas perderia desempenho, + complexidade)
void countingSort(int arr[], int n, int exp){
    int output[n]; // vetor temporario de saida
    int count[10] = {0};

    // Conta ocorrencias de cada digito
    for(int i = 0; i < n; i++){
        int digito = (arr[i] / exp) % 10;
        count[digito]++;
    }

    // Soma acumulada (transforma contagem em posicao)
    for(int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }

    // Monta o vetor de saída (de tras pra frente para manter estabilidade***)
    for(int i = n - 1; i >= 0; i--){
        int digito = (arr[i] / exp) % 10;
        output[count[digito] - 1] = arr[i];
        count[digito]--;
    }

    // Copia de volta para o vetor original
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Funao principal do radix sort
void radixSort(int arr[], int n){
    int max = getMaximo(arr, n);

    // aplica counting sort para cada digito (1, 10, 100 etc)
    for(int exp = 1; max / exp > 0; exp *= 10){
        countingSort(arr, n, exp);
    }
}

int main(){
    int arr[] = {321, 21, 777, 69, 33, 42, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor: \n");

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    radixSort(arr, n); // chama ordenacao
    printf("\n");
    printf("\n");

    printf("Vetor ordenado:\n");

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
