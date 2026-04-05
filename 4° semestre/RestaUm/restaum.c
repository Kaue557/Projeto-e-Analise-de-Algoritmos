/*
========================================== NOMES + RA ==========================================
Aline Vidal (RA: 10721348)

Beatriz Vianna (RA: 10729512)

João Vitor Fernandes Messias (RA: 10723552)

Kauê Lima Rodrigues Meneses (RA: 10410594)

Rayana Pimentel Marques Lopes (RA: 10435370)
================================================================================================
*/


#include <stdio.h>
#include <stdbool.h>
#define N 7

void salvarNoArquivo(int [][N]);

// Vetor de Direcoes (Linhas e Colunas)
int dir_x[4] = {0,0,1,-1};
int dir_y[4] = {1,-1,0,0};

// d = 0 - Direita
// d = 1 - Esquerda
// d = 2 - Baixo
// d = 3 - Cima
bool ehValido(int tabuleiro[][N], int lin, int col, int d){

    if(lin < 0 || lin >= N || col < 0 || col >= N)
        return false;

    if(tabuleiro[lin][col] == -1)
        return false;

    int B_lin = lin + dir_x[d];
    int B_col = col + dir_y[d];
    int C_lin = lin + 2 * dir_x[d];
    int C_col = col + 2 * dir_y[d];

    if(B_lin < 0 || B_lin >= N || B_col < 0 || B_col >= N)
        return false;

    if(C_lin < 0 || C_lin >= N || C_col < 0 || C_col >= N)
        return false;

    if(tabuleiro[B_lin][B_col] == -1 || tabuleiro[C_lin][C_col] == -1)
        return false;

    return (tabuleiro[lin][col] == 1 &&
            tabuleiro[B_lin][B_col] == 1 &&
            tabuleiro[C_lin][C_col] == 0);
}

void movimento(int tabuleiro[][N], int lin, int col, int d){
    int B_lin = lin + dir_x[d];
    int B_col = col + dir_y[d];
    int C_lin = lin + 2 * dir_x[d];
    int C_col = col + 2 * dir_y[d];

    tabuleiro[lin][col] = 0;
    tabuleiro[B_lin][B_col] = 0;
    tabuleiro[C_lin][C_col] = 1;
}

void desfaz(int tabuleiro[][N], int lin, int col, int d){
    int B_lin = lin + dir_x[d];
    int B_col = col + dir_y[d];
    int C_lin = lin + 2 * dir_x[d];
    int C_col = col + 2 * dir_y[d];

    tabuleiro[lin][col] = 1;
    tabuleiro[B_lin][B_col] = 1;
    tabuleiro[C_lin][C_col] = 0;
}

void imprimir(int tabuleiro[][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(tabuleiro[i][j] == -1){
                printf("%c",'#');
            }else if(tabuleiro[i][j] == 1){
                printf("%c",'o');
            }else{
                printf("%c",' ');
            }
        }
        printf("\n");
    }
    printf("\n====================\n\n");
}

bool backtracking(int tabuleiro[][N], int resto){
    if(resto == 1 && tabuleiro[3][3] == 1){
        imprimir(tabuleiro);
        salvarNoArquivo(tabuleiro);
        return true;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < 4; k++){

                if(ehValido(tabuleiro, i, j, k)){
                    movimento(tabuleiro, i, j, k);
                    
                    if(backtracking(tabuleiro, resto - 1)){
                        desfaz(tabuleiro, i, j, k);
                        imprimir(tabuleiro);
                        salvarNoArquivo(tabuleiro);
                        return true;
                    }

                    desfaz(tabuleiro, i, j, k);
                }
            }
        }
    }

    return false;
}

void salvarNoArquivo(int tabuleiro[N][N]){
    FILE *file = fopen("saida.txt","a");
    if(file == NULL){
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(tabuleiro[i][j] == -1){
                fprintf(file,"%c%c",'#','#');
            }else if(tabuleiro[i][j] == 1){
                fprintf(file,"%c%c",'o','o');
            }else{
                fprintf(file,"%c%c",' ',' ');
            }
        }
        fprintf(file,"\n");
    }
    fprintf(file,"\n====================\n\n");

    fclose(file);
}

int main(){

    int tabuleiro[7][7] = {
        {-1,-1,1,1,1,-1,-1},
        {-1,-1,1,1,1,-1,-1},
        {1,1,1,1,1,1,1},
        {1,1,1,0,1,1,1},
        {1,1,1,1,1,1,1},
        {-1,-1,1,1,1,-1,-1},
        {-1,-1,1,1,1,-1,-1}
        };

    FILE *file = fopen("saida.txt","w"); // limpa o arquivo antes de escrever
    fclose(file);

    backtracking(tabuleiro,32);
    return 0;

}