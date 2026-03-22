#include <stdio.h>
#include <stdbool.h>

bool sudoku4x4(int v[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(v[i][j] == 0){
                for(int candidato = 1; candidato <= 4; candidato++){
                    if(verificacao(v, i, j, candidato)){

                    }
                }
            }
            else{
                sudoku4x4(v[i][j+1]);
                sudoku4x4(v[i+1][j]);
            }
        }   
    }
    return true;
}

bool verificacao(int v[4][4], int i, int j, int candidato){
    // verifica linha
    for(int k = 0; k < 4; k++){
        if(v[i][k] == candidato){
            return false;
        }       
    }

    // verifica coluna
    for(int l = 0; l < 4; l++){
        if(v[l][j] == candidato){
            return false;
        }
    }
    return true;
}

int main(){
    int v[4][4] = {
        {0, 2, 4, 0},
        {1, 0, 0, 3},
        {4, 0, 0, 2},
        {0, 1, 3, 0}
    }; 
    sudoku4x4(v);


    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }

    return 0;
}