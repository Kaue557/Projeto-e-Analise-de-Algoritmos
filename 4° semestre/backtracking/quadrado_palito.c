#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
1. (QUADRADO COM PALITOS DE FÓSFOROS) Dado um vetor de inteiros palitos_de_fosforos ,
onde o palitos_de_fosforos[i] é o tamanho do i-esimo palito de fósforo. Deseja-se usar
todos os palitos de fósforos para fazer um quadrado. Não é permitido quebrar nenhum
palito. Escreva uma função que devolva true se você pode construir um quadrado e falso
caso contrário.
Restrições:
• 1 <= len(palitos_de_fosforos) <= 15
• 1 <= palitos_de_fosforos[i] <= 108
*/

bool pode_construir_quadrado(int palitos_de_fosforos[], int n){
    if(n > 15 || n < 1){
        printf("fora de range");
        return false;
    }

    for(int i = 0; i < n; i++){
        if(palitos_de_fosforos[i] < 1 || palitos_de_fosforos[i] > 108){
            printf("fora de range de tamanho");
            return false;
        }

    }
    if(len(palitos_de_fosforos) > 15 || len(palitos_de_fosforos) < 1){
        printf("fora de range");
    }

    return true;
}

int main(){
    int palitos_de_fosforos[] = {1, 1, 2, 2, 2};
    int n = sizeof(palitos_de_fosforos) / sizeof(palitos_de_fosforos[0]);


    return 0;
}