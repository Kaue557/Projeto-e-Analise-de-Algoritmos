/* ENDEREÇAMENTO DIRETO - DADO UM VETOR v = {7, 1, 2, 3, 2, 1, 1, 3, 7, 5, 9}
1. ache o menor elemento de v : k
2. crie um vetor auxiliar w com tamanho k + 1
3. inicialize w com zeros
4. w {0,3,2,2,0,1,0,2,0,1}
5. transfere de w para v:
{1,1,1,2,2,5,7,7,9}
*/
#include <stdio.h>
#include <stdbool.h>

int main(){
    
    int v[] = {7, 1, 2, 3, 2, 1, 1, 3, 7, 5, 9};
    int size = sizeof(v) / sizeof(v[0]);
    int k = v[0]; // MAIOR
    
    // ACHA MAIOR
    for(int i = 0; i < size; i++){
        if(v[i] > k){
            k = v[i];
        }
    }
    printf("maior: %d\n", k);

    int w[k+1] = {0,0,0,0,0,0,0,0,0,0};
    
    int j= 0;
    for(int i = 0; i < k+1; i++){
        while(w[i]--){
            v[j++] = i;

            w[v[i]]++;
        }
        
        
    }


    return 0;
}