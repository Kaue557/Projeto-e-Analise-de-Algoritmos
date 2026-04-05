#include <stdio.h>
#include <stdbool.h>

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
/*
--------------------------------------------------------------LOGICA:

anda por cada posição do sudoku, se encontrar um 0, tenta colocar um número de 1 a 4, verificando se é possível colocar esse número naquela posição.
Se for possível, coloca o número e chama a função recursivamente para tentar resolver o restante do sudoku.
Se a chamada recursiva retornar true, significa que o sudoku foi resolvido e a função retorna true.
Se a chamada recursiva retornar false, significa que o número colocado não levou a uma solução,
então o número é removido (linha v[i][j] = 0) e o controle volta para a função que chamou, tentando outra solução.
Se nenhum número candidato levar a uma solução, a função retorna false, indicando que não há solução para aquele estado do sudoku.

tenta opção A (funcionou)
    tenta opção B (funcionou)
        tenta opção C (funcionou)
            tenta opção D - FALHOU -> volta pra quem chamou (C)
        tenta OUTRA opção C (funcionou)
            tenta OUTRA opção D - FALHOU -> volta pra quem chamou (C),  e se C falhar em todas opções: volta pra quem chamou (B)
    tenta OUTRA opção B
    . . .
*/
bool sudoku4x4(int v[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(v[i][j] == 0){
                for(int candidato = 1; candidato <= 4; candidato++){
                    if(verificacao(v, i, j, candidato)){
                        v[i][j] = candidato;
                        if(sudoku4x4(v)){
                            return true;
                        }
                        else{
                            v[i][j] = 0;
                        }
                    }
                }
                return false;
            }
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

    if(sudoku4x4(v)){
        printf("Solução encontrada:\n");
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                printf("%d ", v[i][j]);
            }
        printf("\n");
    }
    }
    else{
        printf("Não existe solução para este Sudoku.\n");
    }
    
    return 0;
}