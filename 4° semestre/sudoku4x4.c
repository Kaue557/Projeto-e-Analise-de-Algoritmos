#include <stdio.h>
#include <stdbool.h>

void sudoku4x4(int v[4][4]){
    
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(v[i][j] == 0){
                v[i][j] += 1;
                if(v[i][j] == v[i][j+1] || v[i][j] == v[i+1][j]){
                    v[i][j] += 1;
                    sudoku4x4(v[i][j+1]);
                }
            }
            else{
                sudoku4x4(v[i][j+1]);
                sudoku4x4(v[i+1][j]);
            }
        }   
    }
}

bool verificacao(int v[4][4]){
    bool valido = true;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(v[i][j] == v[i][j+1] || v[i][j] == v[i+1][j]){
                valido = false;
            }
        }
    }
    return 1;
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