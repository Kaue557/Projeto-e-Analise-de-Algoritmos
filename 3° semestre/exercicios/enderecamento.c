/*
ENDEREÇAMENTO DIRETO - DADO UM VETOR v = {7, 1, 2, 3, 2, 1, 1, 3, 7, 5, 9}
1. ache o maior elemento de v : k
2. crie um vetor auxiliar w com tamanho k + 1
3. inicialize w com zeros
4. w {0,3,2,2,0,1,0,2,0,1}
5. transfere de w para v:
{1,1,1,2,2,5,7,7,9}
*/
#include <stdio.h>

int main(){
    
    int v[] = {7, 1, 2, 3, 2, 1, 1, 3, 7, 5, 9};
    int size = sizeof(v) / sizeof(v[0]);


    int k = v[0]; // MAIOR
    
    // PASSO 1
    for(int i = 0; i < size; i++){
        if(v[i] > k){
            k = v[i];
        }
    }
    printf("maior: %d\n", k);

    // PASSO 2
    int w[k + 1];

    // PASSO 3
    for (int i = 0; i <= k; i++) {
        w[i] = 0;
    }
    
    // PASSO 4
    int j = 0;
    for(int i = 0; i < size; i++){
        w[v[i]]++;
    }

    // PASSO 5
    int cont = 0;
    for(int i = 0; i < k + 1; i++){ // percorre vetor w
        for(int j = 0; j < size){ // percorre vetor v

        }
        cont = w[i];
        
    }

    return 0;
}